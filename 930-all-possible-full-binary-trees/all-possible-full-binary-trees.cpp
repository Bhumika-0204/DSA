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
    unordered_map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return { new TreeNode(0) };

        if (dp.count(n)) return dp[n];

        vector<TreeNode*> res;

        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            int rightNodes = n - 1 - leftNodes;

            vector<TreeNode*> leftTrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightTrees = allPossibleFBT(rightNodes);

            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return dp[n] = res;
    }
};
