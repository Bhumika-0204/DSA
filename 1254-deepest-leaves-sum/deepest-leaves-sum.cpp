class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) {
            int sz = q.size();
            sum = 0;  // reset for current level

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return sum;
    }
};
