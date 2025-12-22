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
    int totalSum = 0;

    void dfs(TreeNode* root, int curr) {
        if (root == NULL) return;

        curr = curr * 10 + root->val;

        // If leaf node
        if (root->left == NULL && root->right == NULL) {
            totalSum += curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return totalSum;
    }
};
