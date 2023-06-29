class Solution {
public:
    int dp[21][21][2];
    int f(int i,int j,int cho,vector<int>& v){
        if(i==j){
            if(cho==0) return v[i];
            return 0;
        }
        int ans;
        //if(dp[i][j][cho]!=-1) return dp[i][j][cho];
        if(cho==0){
             ans=0;
            int d=f(i+1,j,1,v)+v[i];
            int e=f(i,j-1,1,v)+v[j];
            ans=max(ans,max(d,e));
        }
        else{
             ans=1e9;
            int a=f(i+1,j,0,v);
            int b=f(i,j-1,0,v);
            ans=min(ans,min(a,b));
        }
        return ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int x= f(0,nums.size()-1,0,nums);
        x*=2;
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(x>=sum) return 1;
         return 0;
    }
};