class Solution {
public:
    int dp[101][101];
    int f(int i,int j,vector<vector<int>>& v){
        if(i==v.size() || j==v[0].size()) return 0;
        if(v[i][j]==1) return 0;
        if(i==v.size()-1 && j==v[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=f(i+1,j,v);
        int b=f(i,j+1,v);
        return dp[i][j]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,v);
    }
};