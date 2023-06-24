class Solution {
public:
     int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(1001,vector<int>(1005,-1));
         int ans=2;
         for(int i=0;i<nums.size();i++){
             for(int j=i+1;j<nums.size();j++){
                 int d=nums[j]-nums[i];
                 if(dp[i][d+500]==-1){
                     dp[j][d+500]=2;
                 }
                 else{
                     dp[j][d+500]=1+dp[i][d+500];
                    ans=max(ans,dp[j][d+500]);
                 }
             }
         }
         return ans;
    }
};