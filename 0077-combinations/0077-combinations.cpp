class Solution {
public:
    vector<vector<int>> ans;
    int x;
    void f(int n,int k,vector<int>& v){
        if(k==0){
            ans.push_back(v);
            return;
        }
        for(int i=n;i<=x;i++){
            v.push_back(i);
            f(i+1,k-1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        x=n;
        vector<int> v;
         f(1,k,v);
        return ans;
    }
};