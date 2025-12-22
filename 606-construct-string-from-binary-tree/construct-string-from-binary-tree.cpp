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
    string tree2str(TreeNode* root) {
        if (root == NULL) return "";

        string s = to_string(root->val);

        // Case: left exists OR right exists
        if (root->left != NULL || root->right != NULL) {
            s += "(" + tree2str(root->left) + ")";
        }

        // Case: right exists
        if (root->right != NULL) {
            s += "(" + tree2str(root->right) + ")";
        }

        return s;
    }
};
