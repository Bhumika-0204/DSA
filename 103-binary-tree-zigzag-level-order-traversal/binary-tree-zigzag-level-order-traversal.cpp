class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> levels(s);
            for(int i=0;i<s;i++){
                TreeNode*root=q.front();
                q.pop();
                int idx= flag ? i : s-1-i;
                levels[idx]=root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            flag=!flag;
            result.push_back(levels);
        }
        return result;
    }
};
