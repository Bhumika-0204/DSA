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
    int heightLeft(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int heightRight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->right;
        }
        return h;
    }

    int power2(int h) {
        int res = 1;
        while (h--) res *= 2;
        return res;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = heightLeft(root);
        int rh = heightRight(root);

        if (lh == rh) {
            return power2(lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
