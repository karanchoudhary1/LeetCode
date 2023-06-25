class Solution {
public:
    long long int dp[101][201];
    int m=1e9+7;
    long long f(int st,int fuel,int end,vector<int>& v){
             long long int ans=0;
        if(dp[st][fuel]!=-1) return dp[st][fuel];
         if(st==end){
             ans++;
         }
        for(int i=0;i<v.size();i++){
            if(st==i) continue;
            if(fuel>=abs(v[i]-v[st])) ans=(ans+f(i,fuel-abs(v[i]-v[st]),end,v)%m)%m;
        }
        return dp[st][fuel]=ans%m;
   }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) { 
        memset(dp,-1,sizeof(dp));
        return f(start,fuel,finish,locations)%m;
    }
};