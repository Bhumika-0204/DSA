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
    TreeNode* iop(TreeNode*root){
        TreeNode*pred=root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* ios(TreeNode*root){
        TreeNode*succ=root->right;
        while(succ->left){
            succ=succ->left;
        }
        return succ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
             //case1-koi child nhi h
            if(root->left==NULL &&root->right==NULL){
                return NULL;
            }
            //case2-agr ek child hai
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
            //case3-2child node
            if(root->left!=NULL && root->right!=NULL){
                //replate krdo root ko inorder predecessor/sucessor;
                //replace krne k baad delete the pred/succ
                TreeNode*pred=iop(root);
                root->val=pred->val;
                root->left=deleteNode(root->left,pred->val);
            }
        }
        else if(root->val>key){
            //left m jao
            root->left=deleteNode(root->left,key);
        }
        else{
            //root->val<key :right m jao
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};