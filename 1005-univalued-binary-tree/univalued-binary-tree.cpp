class Solution {
public:
    bool check(TreeNode* root, int val) {
        if (root == NULL) return true;
        if (root->val != val) return false;

        return check(root->left, val) &&
               check(root->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true;
        return check(root, root->val);
    }
};
