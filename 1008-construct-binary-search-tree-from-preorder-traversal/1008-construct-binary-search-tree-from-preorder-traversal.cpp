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
    int i=0;
    TreeNode* f(int mini,int maxi,vector<int>& nums){
       if(i>=nums.size()) return NULL;
        if(nums[i]<=mini || nums[i]>=maxi) return NULL;
        TreeNode* curr=new TreeNode(nums[i]);
        //int d=nums[i];
        i++;
        curr->left=f(mini,nums[i-1],nums);
        //i++;
        curr->right=f(nums[i-1],maxi,nums);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& nums) {
        return f(0,1e9,nums);
    }
};