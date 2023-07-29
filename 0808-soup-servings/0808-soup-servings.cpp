class Solution {
public:
    double f(int x,int y,vector<vector<double>>& dp){
        if(x<=0 && y<=0) return 0.5;
        if(x<=0) return 1;
        if(y<=0) return 0;
        if(dp[x][y]!=-1.0) return dp[x][y];
        double ans=0;
        ans+=0.25*f(x-100,y,dp);
        ans+=0.25*f(x-75,y-25,dp);
        ans+=0.25*f(x-50,y-50,dp);
        ans+=0.25*f(x-25,y-75,dp);
        return dp[x][y]=ans;
    }
    double soupServings(int n) {
        if(n>4800) return 1.0;
        vector<vector<double>> dp(4801,vector<double>(4801,-1.0));
        return f(n,n,dp);
    }
};