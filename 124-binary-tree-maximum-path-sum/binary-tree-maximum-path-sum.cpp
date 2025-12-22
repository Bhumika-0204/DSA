/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        // Max gain from left & right (ignore negative paths)
        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        // Path passing through current node
        int currPath = root->val + leftGain + rightGain;

        // Update global maximum
        maxSum = max(maxSum, currPath);

        // Return max gain to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
