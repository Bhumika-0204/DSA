class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long best = 0;

    long long getTotalSum(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long currSum = root->val + left + right;
        best = max(best, currSum * (totalSum - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return best % MOD;
    }
};
