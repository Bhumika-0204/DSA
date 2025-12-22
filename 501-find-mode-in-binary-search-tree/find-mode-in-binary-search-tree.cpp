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
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        TreeNode* prev = nullptr;
        int cnt = 0, maxCnt = 0;
        inorder(root, prev, cnt, maxCnt, modes);
        return modes;
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, int &cnt, int &maxCnt,
                 vector<int> &modes) {
        if (node == nullptr) return;
        inorder(node->left, prev, cnt, maxCnt, modes);

        if (prev != nullptr && prev->val == node->val) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (cnt > maxCnt) {
            maxCnt = cnt;
            modes.clear();
            modes.push_back(node->val);
        } else if (cnt == maxCnt) {
            modes.push_back(node->val);
        }
        prev = node;

        inorder(node->right, prev, cnt, maxCnt, modes);
    }
};