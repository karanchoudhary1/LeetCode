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
    TreeNode* f(int i,int j,vector<int>& v1,vector<int>& v2){
        if(i>j) return NULL;
        //for(int z=i;z<=j;z++) m[v2[z]]=z+1;
        for(int z=0;z<=v2.size()-1;z++){
            if(v2[z]==v1[preindex]){
                if(f1==0){
                    preindex++;
                    TreeNode* curr=new TreeNode(v2[z]);
                    curr->left=f(i,z-1,v1,v2);
                    curr->right=f(z+1,j,v1,v2);
                    return curr;
                }
            }
        }
        return NULL;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(0,preorder.size()-1,preorder,inorder);
    }
};