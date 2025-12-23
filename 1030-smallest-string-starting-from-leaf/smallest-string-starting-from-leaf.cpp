class Solution {
public:
    string ans = "~"; // higher than 'z'

    void dfs(TreeNode* root, string path) {
        if (root == NULL) return;

        char ch = char('a' + root->val);
        path = ch + path;  // prepend for leaf->root

        if (root->left == NULL && root->right == NULL) {
            if (path < ans)
                ans = path;
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
