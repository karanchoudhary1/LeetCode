class Solution {
public:
    unordered_map<int,int> m;
    int dp[2011][3001];
    bool f(int ind,int jump,vector<int>& nums){
        if(ind==nums.size()-1) return 1;
        if(nums[ind]+jump-1>nums[nums.size()-1]) return 0;
        if(dp[ind][jump]!=-1) return dp[ind][jump];
        bool a=0;
        bool b=0;
        bool c=0;
        if(jump-1>0){
            if(m[nums[ind]+jump-1]!=0) a=f(m[nums[ind]+jump-1],jump-1,nums);
        }
        if(m[nums[ind]+jump]!=0) b=f(m[nums[ind]+jump],jump,nums);
        if(m[nums[ind]+jump+1]!=0) c=f(m[nums[ind]+jump+1],jump+1,nums);
        return dp[ind][jump]=a||b||c;
    }
    bool canCross(vector<int>& stones) {
        for(int i=0;i<stones.size();i++) m[stones[i]]=i;
        if((stones[0]+1)!=stones[1]) return 0;
        memset(dp,-1,sizeof(dp));
        return f(1,1,stones);
    }
};