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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1;
        if(root==NULL) return {};
        stack<TreeNode*> st2;
        //st1.push(new TreeNode(101));
        st1.push(root);
        vector<vector<int>> ans;
        vector<int> v;
        while(st1.size()!=0 || st2.size()!=0){
            if(st1.size()==0){
                while(st2.size()!=0){
                    v.push_back(st2.top()->val);
                    if(st2.top()->right!=NULL) st1.push(st2.top()->right);
                    if(st2.top()->left!=NULL) st1.push(st2.top()->left);
                    st2.pop();
                }
                ans.push_back(v);
                v.clear();
            }
            else{
                while(st1.size()!=0){
                    v.push_back(st1.top()->val);
                    if(st1.top()->left!=NULL) st2.push(st1.top()->left);
                    if(st1.top()->right!=NULL) st2.push(st1.top()->right);
                    st1.pop();
                }
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};