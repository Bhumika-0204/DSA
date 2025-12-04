class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int cur = 0;
        int dir = 1;  // 1 = down, -1 = up

        for (char c : s) {
            rows[cur] += c;
            if (cur == 0) dir = 1;
            else if (cur == numRows - 1) dir = -1;
            cur += dir;
        }

        string res = "";
        for (auto &r : rows) res += r;
        return res;
    }
};
