class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);

        for (auto &t : trust) {
            outdeg[t[0]]++;
            indeg[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (indeg[i] == n - 1 && outdeg[i] == 0)
                return i;
        }
        return -1;
    }
};
