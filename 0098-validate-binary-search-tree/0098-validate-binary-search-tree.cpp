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
    long long int prev=LONG_MIN;
    bool f(TreeNode* root){
        if(root==NULL) return 1;
        bool a=f(root->left);
        if(a==0) return 0;
        if(root->val<=prev) return 0;
        prev=root->val;
        return a && f(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return f(root);
    }
};