class Solution {
public:
    int dp[21][10005];
    int f(int ind,int cs,vector<int>& rods){
        if(ind==rods.size()){
            if(cs==0) return 0;
            return INT_MIN;
        }
        if(dp[ind][cs+5001]!=-1) return dp[ind][cs+5001];
        int a=f(ind+1,cs,rods);
        int b=f(ind+1,cs+rods[ind],rods);
        int c=rods[ind]+f(ind+1,cs-rods[ind],rods);
        return dp[ind][cs+5001]=max(a,max(b,c)); 
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        //for(int i=0;i<rods.size();i++) sum+=rods[i];
        return f(0,0,rods);
    }
};