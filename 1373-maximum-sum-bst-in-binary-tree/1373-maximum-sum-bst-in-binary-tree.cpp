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
    // bool mini maxi sum
    vector<int> f(TreeNode* root){
        if(root==NULL) return {1,100000,-100000,0};
        vector<int> a=f(root->left);
        vector<int> b=f(root->right);
        if(a[0]==1 && b[0]==1 && root->val>a[2] && root->val<b[1]){
            ans=max(ans,root->val+a[3]+b[3]);
            int q=min(root->val,min(a[1],b[1]));
            int w=max(root->val,max(a[2],b[2]));
            return {1,q,w,root->val+a[3]+b[3]};
        }
        return {0,100000,-100000,0};
    }
    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};