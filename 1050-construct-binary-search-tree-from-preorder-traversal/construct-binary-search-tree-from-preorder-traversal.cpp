class Solution {
public:
    int idx = 0;

    TreeNode* build(vector<int>& pre, int low, int high) {
        if (idx >= pre.size()) return NULL;

        int val = pre[idx];
        if (val < low || val > high) return NULL;

        TreeNode* root = new TreeNode(val);
        idx++;

        root->left = build(pre, low, val - 1);
        root->right = build(pre, val + 1, high);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        return build(preorder, INT_MIN, INT_MAX);
    }
};
