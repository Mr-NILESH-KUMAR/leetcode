class Solution {
public:
    string convert(string s, int num ) {
        if (num == 1 || num >= s.length()) {
            return s;
        }

        int idx = 0, d = 1;
        vector<vector<char>> rows(num);

        for (char c : s) {
            rows[idx].push_back(c);
            if (idx == 0) {
                d = 1;
            } else if (idx == num - 1) {
                d = -1;
            }
            idx += d;
        }

        string result;
        for (const auto& row : rows) {
            for (char c : row) {
                result += c;
            }
        }

        return result;        
    }
};