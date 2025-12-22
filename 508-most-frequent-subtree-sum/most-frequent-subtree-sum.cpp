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
    unordered_map<int,int> freq;
    int maxFreq = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int sum = left + right + root->val;
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
