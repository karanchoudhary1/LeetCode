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
    int f(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return 0;
        int a=1e9;
        int b=1e9;
        if(root->left!=NULL) a=f(root->left);
        if(root->right!=NULL) b=f(root->right);
        
        return min(a,b)+1;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return f(root)+1;
    }
};