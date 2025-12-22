class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int sum = curr.second;

            if (node->left == NULL && node->right == NULL && sum == targetSum)
                return true;

            if (node->left)
                q.push({node->left, sum + node->left->val});

            if (node->right)
                q.push({node->right, sum + node->right->val});
        }
        return false;
    }
};
