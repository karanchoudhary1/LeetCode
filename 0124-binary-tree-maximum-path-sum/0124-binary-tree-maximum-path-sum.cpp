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
    int ans=INT_MIN;
    int f(TreeNode* root){
        if(root==NULL) return 0;
        int a=f(root->left);
        int b=f(root->right);
        ans=max(ans,a+b+root->val);
        ans=max(ans,a+root->val);
        ans=max(ans,b+root->val);
        ans=max(ans,root->val);
        int x=max(root->val,max(root->val+a,root->val+b));
        return x;
    }
    int maxPathSum(TreeNode* root) {
         f(root);
        return ans;
    }
};