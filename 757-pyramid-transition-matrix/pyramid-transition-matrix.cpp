class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool solve(string curr) {
        // If pyramid is complete
        if (curr.size() == 1) return true;

        // If already computed and failed
        if (memo.count(curr)) return memo[curr];

        int n = curr.size();
        vector<string> choices(n - 1);

        // Build all possible choices for each adjacent pair
        for (int i = 0; i < n - 1; i++) {
            string key = curr.substr(i, 2);
            if (!mp.count(key)) {
                memo[curr] = false;
                return false;
            }
            for (char c : mp[key]) {
                choices[i].push_back(c);
            }
        }

        // Generate all possible next rows using DFS
        function<bool(int, string&)> build = [&](int idx, string &next) {
            if (idx == choices.size()) {
                return solve(next);
            }
            for (char c : choices[idx]) {
                next.push_back(c);
                if (build(idx + 1, next)) return true;
                next.pop_back();
            }
            return false;
        };

        string next = "";
        bool ans = build(0, next);
        memo[curr] = ans;
        return ans;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return solve(bottom);
    }
};
