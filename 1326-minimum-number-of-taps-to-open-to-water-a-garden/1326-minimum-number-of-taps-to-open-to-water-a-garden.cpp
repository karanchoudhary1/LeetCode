class Solution {
public:
    int d;
    int dp[10008];
    long long int f(int i,int prev,vector<pair<int,int>>& v){
        if(prev>=d) return 0;
        if(i==v.size()) return INT_MAX;
        if(v[i].first>prev) return INT_MAX;
        if(dp[prev]!=-1) return dp[prev];
        long long int a=f(i+1,max(prev,v[i].second),v)+1;
        long long int b=f(i+1,prev,v);
        return dp[prev]=min(a,b);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        memset(dp,-1,sizeof(dp));
        d=n;
        for(int i=0;i<ranges.size();i++){
            v.push_back({i-ranges[i],i+ranges[i]});
        }
        sort(v.begin(),v.end());
        long long int x= f(0,0,v);
        if(x>=INT_MAX) return -1;
        return (int)x;
    }
};