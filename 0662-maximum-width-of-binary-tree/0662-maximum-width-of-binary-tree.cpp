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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        q.push({new TreeNode(-101),0});
        long long int ans=1;
        long long int lft=1e9;
        long long int prev=0;
        long long int rgt=0;
        while(q.size()!=0){
            auto it=q.front();
            q.pop();
            TreeNode* curr=it.first;
            long long int dis=it.second;
            dis-=prev;
            if(curr->val==-101){
                ans=max(ans,rgt-lft+1);
                q.push({new TreeNode(-101),0});
                if(q.size()==1) return ans;
                prev=q.front().second;
                lft=1e9;
                rgt=0;
                continue;
            }
            lft=min(lft,dis);
            rgt=max(rgt,dis);
            if(dis==-1){
                if(curr->left!=NULL) q.push({curr->left,1});
                if(curr->left!=NULL) q.push({curr->right,2});
            }
            else{
                if(curr->left!=NULL) q.push({curr->left,2*(dis)+1});
                if(curr->right!=NULL) q.push({curr->right,2*(dis)+2});
            }
        }
        return (int)ans;
    }
};