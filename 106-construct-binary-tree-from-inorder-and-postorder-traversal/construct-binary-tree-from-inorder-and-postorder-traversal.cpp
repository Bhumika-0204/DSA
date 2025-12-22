class Solution {
public:
    unordered_map<int,int> mp;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = mp[rootVal];

        root->right = build(postorder, idx + 1, inEnd);
        root->left = build(postorder, inStart, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(postorder, 0, inorder.size() - 1);
    }
};
