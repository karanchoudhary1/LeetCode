class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> h(n,1);
    int ans=0;
    int maxl=1;
    for(int i=0; i<=n-1; i++){
        for(int prev= 0; prev <=i-1; prev ++){
            if( arr[i]>arr[prev] && dp[i]>=dp[prev]){
               if(dp[i]==dp[prev]) {
                   h[i]=h[prev];
                   dp[i]=1+dp[i];
               }
               else if(dp[i]==dp[prev]+1){
                   h[i]+=h[prev];
               }
            }
        }
        if(dp[i]>maxl) {
                ans=h[i];
                maxl=dp[i];
            }
            else if(maxl==dp[i]){
                ans+=h[i];
            }
    }
        
    return ans;
    }
};