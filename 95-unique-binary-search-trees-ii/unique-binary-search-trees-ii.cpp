/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> ans;

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = build(start, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, end);

            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
