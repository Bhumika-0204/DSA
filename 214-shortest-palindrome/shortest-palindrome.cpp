class Solution {
public:
    int lpsLast(const string &t) {
        int n = t.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (t[i] == t[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps[n - 1];
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;

        int palLen = lpsLast(temp);
        string add = s.substr(palLen);
        reverse(add.begin(), add.end());
        return add + s;
    }
};
