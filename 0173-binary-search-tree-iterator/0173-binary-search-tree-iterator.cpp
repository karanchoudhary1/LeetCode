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
class BSTIterator {
public:
    queue<TreeNode*> q;
    void f(TreeNode* root){
        if(root==NULL) return ;
        f(root->left);
        q.push(root);
        f(root->right);
    }
    BSTIterator(TreeNode* root) {
        f(root);
    }
    
    int next() {
        TreeNode* curr=q.front();
        q.pop();
        return curr->val;
    }
    
    bool hasNext() {
        TreeNode* curr=q.front();
        if(q.size()==0) return 0; 
        return 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */