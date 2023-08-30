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
    int prev=0;
    map<int,int> m;
    TreeNode* f(int i,int j,vector<int>& v1,vector<int>& v2){
         if(i>j) return NULL;
         TreeNode* curr=new TreeNode(v2[prev]);
        prev--;
        int ind;
        for(int z=i;z<=j;z++){
            if(v2[prev+1]==v1[z]){
                ind=z;
                break;
            }
        }
        curr->right=f(ind+1,j,v1,v2);
        curr->left=f(i,ind-1,v1,v2);
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         prev=inorder.size()-1;
        return f(0,inorder.size()-1,inorder,postorder);
    }
};