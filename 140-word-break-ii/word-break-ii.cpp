class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];

        vector<string> res;

        if (s.empty()) {
            res.push_back("");
            return res;
        }

        for (int len = 1; len <= s.size(); len++) {
            string prefix = s.substr(0, len);
            if (dict.count(prefix)) {
                vector<string> suffixWays = dfs(s.substr(len));
                for (string way : suffixWays) {
                    if (way.empty())
                        res.push_back(prefix);
                    else
                        res.push_back(prefix + " " + way);
                }
            }
        }
        memo[s] = res;
        return res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string w : wordDict)
            dict.insert(w);
        return dfs(s);
    }
};
