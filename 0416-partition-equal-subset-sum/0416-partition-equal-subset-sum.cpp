class Solution {
public:
    bool f(int i,int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(sum>10000 || sum<-10000) return 0;
        if(i==nums.size()){
            if(sum==0) return 1;
            return 0;
        }
        if(dp[i][sum+10000]!=-1) return dp[i][sum+10000];
        bool a= f(i+1,sum+nums[i],nums,dp);
        bool b=f(i+1,sum-nums[i],nums,dp);
        return dp[i][sum+10000]=a||b; 
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(20005,-1));
        return f(0,0,nums,dp);
    }
};