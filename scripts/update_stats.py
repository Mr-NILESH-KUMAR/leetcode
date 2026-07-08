#!/usr/bin/env python3
"""
Fetches LeetCode stats for a given username and rewrites the block of
README.md between the STATS markers. Designed to be run by the
'update-readme.yml' GitHub Action on a daily schedule.
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

STATS_API_URL = f"https://leetcode-stats-api.herokuapp.com/{LEETCODE_USERNAME}"


def fetch_stats():
    """Hit the public LeetCode stats API and return parsed JSON."""
    req = urllib.request.Request(
        STATS_API_URL, headers={"User-Agent": "Mozilla/5.0"}
    )
    with urllib.request.urlopen(req, timeout=20) as resp:
        data = json.loads(resp.read().decode("utf-8"))
    if data.get("status") != "success":
        raise RuntimeError(f"LeetCode stats API returned an error: {data}")
    return data


def build_table(stats: dict) -> str:
    today = datetime.date.today().isoformat()
    easy = stats.get("easySolved", "—")
    medium = stats.get("mediumSolved", "—")
    hard = stats.get("hardSolved", "—")
    total = stats.get("totalSolved", "—")
    total_q = stats.get("totalQuestions", "—")
    ranking = stats.get("ranking", "—")
    acceptance = stats.get("acceptanceRate", "—")

    table = f"""| 🟢 Easy | 🟡 Medium | 🔴 Hard | 📅 Total Solved | 🏆 Ranking | 📈 Acceptance Rate |
|:---:|:---:|:---:|:---:|:---:|:---:|
| {easy} | {medium} | {hard} | {total} / {total_q} | {ranking} | {acceptance}% |

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
