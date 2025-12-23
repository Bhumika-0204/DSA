class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);

        TreeNode* dummy = new TreeNode(-1);
        TreeNode* curr = dummy;

        for (TreeNode* node : v) {
            node->left = NULL;
            curr->right = node;
            curr = node;
        }
        curr->right = NULL;

        return dummy->right;
    }
};
