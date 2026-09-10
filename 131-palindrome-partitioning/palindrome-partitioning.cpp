class Solution {
public:
    int n;
    bool ispalindrome(string &s,int l,int r){
        while (r > l) {
            if (s[l] != s[r]) {
                return false;
            }
                l++;
                r--;
        }
            return true;
    }
    void backtrack(string &s,int idx, vector<string> curr,vector<vector<string>>& ans){
        if (idx == n) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (ispalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> curr;
        vector<vector<string>> ans;
        backtrack(s, 0, curr, ans);
        return ans;
    }
};