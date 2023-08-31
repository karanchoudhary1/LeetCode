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
    TreeNode* f(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        TreeNode* a=NULL;
        TreeNode* b=NULL;
        if(root==p) return p;
        if(root==q) return q;
        a=f(root->left,p,q);
        b=f(root->right,p,q);
        if(a==NULL && b==NULL) return NULL;
        if(a!=NULL && b!=NULL) return root;
        if(a!=NULL) return a;
        return b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};