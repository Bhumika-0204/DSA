class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                nullFound = true;
            } else {
                if (nullFound) return false; // violation
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
