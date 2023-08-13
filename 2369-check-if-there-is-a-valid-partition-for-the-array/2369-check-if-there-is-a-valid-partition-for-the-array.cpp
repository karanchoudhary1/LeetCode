class Solution {
public:
    int dp[100001];
    bool f(int i,int j,vector<int>& nums){
          if(i==nums.size())return 1;
           if(dp[i]!=-1) return dp[i];
             if(i+1<nums.size() && nums[i]==nums[i+1]){
                 bool x=f(i+2,j,nums);
                 if(x==1) return 1;
             }
             if(i+2<nums.size()){
                 if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                     bool x=f(i+3,j,nums);
                     if(x==1) return 1;
                 }
                 if(1+nums[i]==nums[i+1] && 1+nums[i+1]==nums[i+2]){
                     bool x=f(i+3,j,nums);
                     if(x==1) return 1;
                 }
             }
           return dp[i]=0;
         }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums.size()-1,nums);
    }
};