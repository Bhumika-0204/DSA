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
    unordered_map<int, int> postIndex;

    TreeNode* build(vector<int>& preorder, int preL, int preR,
                    vector<int>& postorder, int postL, int postR) {
        if (preL > preR) return NULL;

        TreeNode* root = new TreeNode(preorder[preL]);
        if (preL == preR) return root;

        int leftRootVal = preorder[preL + 1];
        int idx = postIndex[leftRootVal];
        int leftSize = idx - postL + 1;

        root->left = build(preorder, preL + 1, preL + leftSize,
                           postorder, postL, idx);

        root->right = build(preorder, preL + leftSize + 1, preR,
                            postorder, idx + 1, postR - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            postIndex[postorder[i]] = i;
        }
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};
