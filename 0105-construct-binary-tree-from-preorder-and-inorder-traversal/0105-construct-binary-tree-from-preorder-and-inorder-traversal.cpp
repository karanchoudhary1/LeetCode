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
    bool f1=0;
    int preindex=0;
    map<int,int> m;
    TreeNode* f(int i,int j,vector<int>& v1,vector<int>& v2){
        if(i>j) return NULL;
                if(f1==0){
                    int ind=m[v1[preindex]];
                    TreeNode* curr=new TreeNode(v1[preindex]);
                    preindex++;
                    curr->left=f(i,ind-1,v1,v2);
                    curr->right=f(ind+1,j,v1,v2);
                    return curr;
                }
        return NULL;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return f(0,preorder.size()-1,preorder,inorder);
    }
};