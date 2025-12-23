class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes; // col, row, val
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end(),
            [](auto &a, auto &b) {
                if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
                if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
                return get<2>(a) < get<2>(b);
            });

        vector<vector<int>> ans;
        int prevCol = INT_MIN;

        for (auto &t : nodes) {
            int col = get<0>(t);
            int val = get<2>(t);

            if (col != prevCol) {
                ans.push_back(vector<int>());
                prevCol = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }

    void dfs(TreeNode* root, int row, int col,
             vector<tuple<int,int,int>>& nodes) {
        if (!root) return;
        nodes.push_back({col, row, root->val});
        dfs(root->left, row + 1, col - 1, nodes);
        dfs(root->right, row + 1, col + 1, nodes);
    }
};
