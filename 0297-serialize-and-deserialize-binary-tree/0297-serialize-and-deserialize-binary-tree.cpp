/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
            ans+="1001 ";
            continue;
            }
            ans+=to_string(curr->val);
            ans+=" ";
            q.push(curr->left);
            q.push(curr->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        queue<TreeNode*> q;
        TreeNode* res;
        int cnt=2;
        string x="";
        bool f1=0;
        for(int i=0;i<s.length();i++){
            if(q.size()==0 && f1==1) break;
            if(f1==1 && q.front()==NULL){
                q.pop();
              i--;
                continue;
            }
            if(s[i]==' '){
                if(f1==0){
                    TreeNode* curr1=new TreeNode(stoi(x));
                    if(curr1->val==1001) return NULL;
                    q.push(curr1);
                    res=curr1;
                    f1=1;
                    x="";
                    continue;
                }
                int v=stoi(x);
                if(v==1001){
                    TreeNode* curr=NULL;
                    if(cnt%2==0) q.front()->left=NULL;
                    else{
                        q.front()->right=curr;
                        q.pop();
                    }
                    cnt++;
                    q.push(NULL);
                    x="";
                }
                else{
                TreeNode*curr=new TreeNode(v);
                     if(cnt%2==0) q.front()->left=curr;
                    else{
                        q.front()->right=curr;
                        q.pop();
                    }
                    cnt++;
                     x="";
                    q.push(curr);
                    }
            }
            else x+=s[i];
        }
        return res;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));