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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
         map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(q.size()!=0){
            auto it=q.front();
            int lvl=it.second.second;
            int res=it.second.first;
            TreeNode* curr=it.first;
            q.pop();
            m[res][lvl].push_back(curr->val);
            if(curr->left!=NULL) q.push({curr->left,{res-1,lvl+1}});
            if(curr->right!=NULL) q.push({curr->right,{res+1,lvl+1}});
        }
        for(auto x:m){
            vector<int> jus;
            map<int,vector<int>> mp=x.second;
            for(auto y:mp){
                sort(y.second.begin(),y.second.end());
                for(int i=0;i<y.second.size();i++) jus.push_back(y.second[i]);
            }
            ans.push_back(jus);
        }
       return ans; 
    }
};