class Solution {
public:
    int dp[201][1001];
    int f(int i,vector<int>& v,int tar){
        if(i==v.size()){
            if(tar==0){
                return 1;
            }
            return 0;
        }
        if(tar<0) return 0;
        if(dp[i][tar]!=-1) return dp[i][tar];
        int a=f(0,v,tar-v[i]);
        int b=f(i+1,v,tar);
        return dp[i][tar]=a+b;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums,target);
    }
};