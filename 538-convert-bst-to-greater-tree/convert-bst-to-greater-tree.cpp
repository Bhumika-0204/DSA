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
    int sum = 0;

    void reverseInorder(TreeNode* root) {
        if (root == NULL) return;

        reverseInorder(root->right);

        sum += root->val;
        root->val = sum;

        reverseInorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};
