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
    // Build tree (level order with -1 for NULL)
    TreeNode* buildTree(vector<int>& arr) {
        if (arr.size() == 0 || arr[0] == -1) return NULL;

        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            TreeNode* cur = q.front(); q.pop();

            if (arr[i] != -1) {
                cur->left = new TreeNode(arr[i]);
                q.push(cur->left);
            }
            i++;

            if (i >= arr.size()) break;

            if (arr[i] != -1) {
                cur->right = new TreeNode(arr[i]);
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }

    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);

        TreeNode *first = NULL, *second = NULL;

        // Find 2 misplaced nodes
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i]->val > nodes[i+1]->val) {
                if (!first) first = nodes[i];
                second = nodes[i+1];
            }
        }

        // Swap their values
        if (first && second)
            swap(first->val, second->val);
    }
};