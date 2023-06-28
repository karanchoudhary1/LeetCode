class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>& v){
        if(i==v.size() || j==v[0].size()) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=f(i+1,j,v);
        int b=f(i,j+1,v);
        a=min(a,b);
        if(a==1e9) {
            if(v[i][j]<0) return abs(v[i][j])+1;
            else return 1;
        }
        if(v[i][j]>=a) return 1;
        else return dp[i][j]=a-v[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,dungeon);
    }
};