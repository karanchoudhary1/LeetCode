class Solution {
public:
    int x;
    int dp[15][1<<14][20];
    int f(int ind,int mask,int cs,int tot,vector<int>& v){
        if(mask==x) return 0;
        if(ind==v.size()) return 1e9;
        if(dp[ind][mask][cs]!=-1) return dp[ind][mask][cs];
        int b=1e9;
        if(!(mask&(1<<ind))){
            if(cs+v[ind]<=tot) b=f(ind+1,mask|1<<ind,cs+v[ind],tot,v);
             else b=f(0,mask|1<<ind,v[ind],tot,v)+1;
        }
                int a=f(ind+1,mask,cs,tot,v);
        return dp[ind][mask][cs]=min(a,b);
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        x=pow(2,tasks.size())-1;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,sessionTime,tasks)+1;
    }
};