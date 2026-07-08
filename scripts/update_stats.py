#!/usr/bin/env python3
"""
Fetches LeetCode stats for a given username directly from LeetCode's own
public GraphQL endpoint (no third-party API, so no random downtime) and
rewrites the block of README.md between the STATS markers. Designed to be
run by the 'update-readme.yml' GitHub Action on a daily schedule.
"""

import datetime
import re
import sys
import urllib.request
import json

LEETCODE_USERNAME = "ni_lesh_"
README_PATH = "README.md"

START_MARKER = "<!--START_SECTION:leetcode-stats-->"
END_MARKER = "<!--END_SECTION:leetcode-stats-->"

GRAPHQL_URL = "https://leetcode.com/graphql"
FALLBACK_API_URL = f"https://leetcode-stats.tashif.codes/{LEETCODE_USERNAME}"

QUERY = """
query userProblemsSolved($username: String!) {
  matchedUser(username: $username) {
    submitStatsGlobal {
      acSubmissionNum {
        difficulty
        count
      }
    }
    profile {
      ranking
    }
  }
  allQuestionsCount {
    difficulty
    count
  }
}
"""


def _http_get_json(url, method="GET", payload=None, extra_headers=None):
    headers = {
        "User-Agent": "Mozilla/5.0 (GitHub Actions README bot)",
    }
    if extra_headers:
        headers.update(extra_headers)
    req = urllib.request.Request(url, data=payload, method=method, headers=headers)
    with urllib.request.urlopen(req, timeout=20) as resp:
        return json.loads(resp.read().decode("utf-8"))


def fetch_from_graphql():
    """Primary source: LeetCode's own public GraphQL endpoint."""
    payload = json.dumps(
        {
            "query": QUERY,
            "variables": {"username": LEETCODE_USERNAME},
            "operationName": "userProblemsSolved",
        }
    ).encode("utf-8")

    data = _http_get_json(
        GRAPHQL_URL,
        method="POST",
        payload=payload,
        extra_headers={
            "Content-Type": "application/json",
            "Referer": f"https://leetcode.com/u/{LEETCODE_USERNAME}/",
        },
    )

    if "errors" in data:
        raise RuntimeError(f"LeetCode GraphQL API returned errors: {data['errors']}")

    matched_user = data.get("data", {}).get("matchedUser")
    if not matched_user:
        raise RuntimeError(f"No user found for username '{LEETCODE_USERNAME}'.")

    ac_counts = {
        row["difficulty"]: row["count"]
        for row in matched_user["submitStatsGlobal"]["acSubmissionNum"]
    }
    total_counts = {
        row["difficulty"]: row["count"] for row in data["data"]["allQuestionsCount"]
    }
    easy = ac_counts.get("Easy", 0)
    medium = ac_counts.get("Medium", 0)
    hard = ac_counts.get("Hard", 0)

    return {
        "easy": easy,
        "medium": medium,
        "hard": hard,
        "total": ac_counts.get("All", easy + medium + hard),
        "total_q": total_counts.get("All", "—"),
        "ranking": matched_user["profile"]["ranking"],
    }


def fetch_from_fallback_api():
    """Backup source: a second independently hosted public stats API,
    used only if LeetCode's own GraphQL endpoint is unreachable."""
    data = _http_get_json(FALLBACK_API_URL)
    if data.get("status") == "error":
        raise RuntimeError(f"Fallback API returned an error: {data}")

    return {
        "easy": data.get("easySolved", 0),
        "medium": data.get("mediumSolved", 0),
        "hard": data.get("hardSolved", 0),
        "total": data.get("totalSolved", 0),
        "total_q": data.get("totalQuestions", "—"),
        "ranking": data.get("ranking", "—"),
    }


def fetch_stats():
    """Try the official LeetCode API first; fall back to a secondary public
    API if that fails for any reason (downtime, rate limiting, etc.)."""
    try:
        return fetch_from_graphql()
    except Exception as primary_error:
        print(
            f"Primary source (LeetCode GraphQL) failed: {primary_error}\n"
            "Falling back to secondary stats API...",
            file=sys.stderr,
        )
        return fetch_from_fallback_api()


def build_table(stats: dict) -> str:
    today = datetime.date.today().isoformat()

    table = f"""| 🟢 Easy | 🟡 Medium | 🔴 Hard | 📅 Total Solved | 🏆 Ranking |
|:---:|:---:|:---:|:---:|:---:|
| {stats['easy']} | {stats['medium']} | {stats['hard']} | {stats['total']} / {stats['total_q']} | {stats['ranking']} |

<sub>Last auto-updated: {today} UTC · via GitHub Actions</sub>"""
    return table


def update_readme(table: str):
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    pattern = re.compile(
        re.escape(START_MARKER) + r".*?" + re.escape(END_MARKER),
        re.DOTALL,
    )
    replacement = f"{START_MARKER}\n{table}\n{END_MARKER}"

    if not pattern.search(content):
        print(
            f"ERROR: Could not find markers {START_MARKER} / {END_MARKER} "
            "in README.md. Add them where you want the stats table to live.",
            file=sys.stderr,
        )
        sys.exit(1)

    new_content = pattern.sub(replacement, content)

    if new_content != content:
        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(new_content)
        print("README.md updated with fresh stats.")
    else:
        print("No changes — README.md already up to date.")


if __name__ == "__main__":
    try:
        stats = fetch_stats()
    except Exception as e:
        print(f"Failed to fetch LeetCode stats: {e}", file=sys.stderr)
        sys.exit(1)

    table = build_table(stats)
    update_readme(table)
