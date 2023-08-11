class Solution {
public:
    int dp[301][5001];
    int f(int i,int am,vector<int>& coins){
        if(am==0) return 1;
        if(am<0) return 0;
        if(dp[i][am]!=-1) return dp[i][am];
        if(i==coins.size()) return 0;
        int a=f(i+1,am,coins);
        int b=f(i,am-coins[i],coins);
        return dp[i][am]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return f(0,amount,coins);
    }
};