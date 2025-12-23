class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;

        queue<pair<TreeNode*, TreeNode*>> q; // node, parent
        q.push({root, NULL});

        while (!q.empty()) {
            int sz = q.size();
            TreeNode *px = NULL, *py = NULL;

            for (int i = 0; i < sz; i++) {
                auto cur = q.front(); q.pop();
                TreeNode* node = cur.first;
                TreeNode* parent = cur.second;

                if (node->val == x) px = parent;
                if (node->val == y) py = parent;

                if (node->left)
                    q.push({node->left, node});
                if (node->right)
                    q.push({node->right, node});
            }

            if (px && py) return px != py;
            if (px || py) return false; // found only one at this level
        }
        return false;
    }
};
