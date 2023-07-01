class Solution {
public:
    int x;
    //int dp[]
        int dp[1<<14][20];

    int f(int mask,int cs,int tot,vector<int>& v){
        if(mask==x) {
            return 0;
        }
        if(dp[mask][cs]!=-1) return dp[mask][cs];
        int ans=1e9;
        for(int i=0;i<v.size();i++){
            if(mask==x) return 0;
            if(mask&1<<i) continue;
            int a=1e9;
            int b=1e9;
            if(cs+v[i]<=tot) a=f(mask|1<<i,cs+v[i],tot,v);
             b=f(mask|1<<i,v[i],tot,v)+1;
            ans=min(a,min(ans,b));
        }
        return dp[mask][cs]=ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        x=pow(2,tasks.size())-1;
                memset(dp,-1,sizeof(dp));

    return f(0,0,sessionTime,tasks)+1;
    }
};