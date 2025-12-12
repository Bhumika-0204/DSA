class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int start, int n, int k) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        // Pruning: ensure enough elements left
        for(int i = start; i <= n - (k - curr.size()) + 1; i++) {
            curr.push_back(i);
            backtrack(i + 1, n, k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};
