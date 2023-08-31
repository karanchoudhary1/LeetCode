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
    bool f(long long int mini,long long int maxi,TreeNode* root){
        if(root==NULL) return 1;
        if(root->val<=mini || root->val>=maxi) return 0;
        return f(mini,root->val,root->left) && f(root->val,maxi,root->right);
    }
    bool isValidBST(TreeNode* root) {
        return f(-1e15,1e15,root);
    }
};