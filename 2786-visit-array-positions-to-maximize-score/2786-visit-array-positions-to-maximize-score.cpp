class Solution {
public:
    long long int dp[100005][2];
    long long f(int i,int par,int x,vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i][par]!=-1) return dp[i][par];
        long long a=0;
        int zx=0;
        if(nums[i]%2==1) zx=1;
        if(par==zx) a=nums[i]+f(i+1,par,x,nums);
        else a=nums[i]-x+f(i+1,zx,x,nums);
        long long b=f(i+1,par,x,nums);
        return dp[i][par]=max(a,b);
    }
    long long maxScore(vector<int>& nums, int x) {
        memset(dp,-1,sizeof(dp));
        int xt=0;
        if(nums[0]%2==0) xt=0;
        else xt=1;
        return (long long)nums[0]+f(1,xt,x,nums);
    }
};