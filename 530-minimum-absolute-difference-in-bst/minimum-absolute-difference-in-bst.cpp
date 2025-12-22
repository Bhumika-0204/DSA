/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = INT_MAX;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        if (prev != NULL) {
            ans = min(ans, abs(root->val - prev->val));
        }
        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
