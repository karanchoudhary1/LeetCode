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
    TreeNode* f(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* a=f(root->left);
        TreeNode* b=f(root->right);
        if(a!=NULL && b!=NULL){
            root->right=a;
            TreeNode* q=root;
            while(root->right!=NULL) root=root->right;
            root->right=b;
            root=q;
        }
        else {
            if(a==NULL && b==NULL) root->right=NULL;
            else if(a==NULL) root->right=b;
            else if(b==NULL) root->right=a;
        }
        root->left=NULL;
        return root;
    }
    void flatten(TreeNode* root) {
        TreeNode* st=root;
         f(root);
        //root->right=NULL;
        //root=st;
    }
};