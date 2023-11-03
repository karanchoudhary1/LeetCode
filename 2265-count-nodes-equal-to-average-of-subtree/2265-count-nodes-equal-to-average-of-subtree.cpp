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
    int ans=0;
    pair<float,float> f(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<float,float> a=f(root->left);
        //if(a.first+root->val/(a.second+1)==root->val) ans++;
        pair<float,float> b=f(root->right);
        float d=(a.first+b.first+root->val)/(b.second+1+a.second);
        int x=(int)d;
            if(x==root->val) ans++;
        
        return {a.first+b.first+root->val,a.second+b.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
         f(root);
        return ans;
    }
};