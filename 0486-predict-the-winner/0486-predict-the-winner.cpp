class Solution {
public:
    int dp[20][20][2];
    int f(int st,int end,int cho,vector<int>& nums){
        if(st==end) return nums[st];
        if(cho==0){
            int a=f(st+1,end,1,nums)+nums[st];
            int b=f(st,end-1,1,nums)+nums[end];
            return max(a,b);
        }
        else{
             int a=f(st+1,end,0,nums);
            int b=f(st,end-1,0,nums);
            return min(a,b);
        }
        return 0;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int x=f(0,nums.size()-1,0,nums);
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int d=sum/2;
        if(sum%2==1) d++;
        if(x>=d) return 1;
        return 0;
    }
};