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
private:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* buildBalancedBST(vector<int>& arr, int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildBalancedBST(arr, l, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, r);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return buildBalancedBST(arr, 0, arr.size() - 1);
    }
};
