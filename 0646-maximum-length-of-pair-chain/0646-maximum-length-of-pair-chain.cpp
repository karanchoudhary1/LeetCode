class Solution {
public:
    static bool mycmp(const vector<int>& v1, const vector<int>& v2)
      {
    return v1[1] < v2[1];
      }
    int dp[1002][1002];
    int f(int ind,int prev,vector<vector<int>>& v){
        if(ind==v.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int a=f(ind+1,prev,v);
        int b=0;
        if(prev==-1 || v[ind][0]>v[prev][1]) b=f(ind+1,ind,v)+1;
        return dp[ind][prev+1]=max(a,b);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end(),mycmp);
        for(int i=0;i<pairs.size();i++) cout<<pairs[i][0]<<"    "<<pairs[i][1]<<"    ";
        return f(0,-1,pairs);
    }
};