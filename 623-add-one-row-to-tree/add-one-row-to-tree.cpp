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
    void dfs(TreeNode* root, int val, int depth, int curr) {
        if (root == NULL) return;

        if (curr == depth - 1) {
            TreeNode* leftOld = root->left;
            TreeNode* rightOld = root->right;

            root->left = new TreeNode(val);
            root->left->left = leftOld;

            root->right = new TreeNode(val);
            root->right->right = rightOld;
            return;
        }

        dfs(root->left, val, depth, curr + 1);
        dfs(root->right, val, depth, curr + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        dfs(root, val, depth, 1);
        return root;
    }
};
