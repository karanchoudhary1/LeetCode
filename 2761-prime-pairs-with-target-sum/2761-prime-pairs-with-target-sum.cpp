class Solution {
public:
    bool isP(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
    vector<vector<int>> findPrimePairs(int n) {
            vector<vector<int>> ans;

            vector<bool> vis(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(vis[i]==1){
                for(int j=2*i;j<=n;j+=i) vis[j]=0;
            }
        }
        if(n==2) return {};
        for(int i=2;i<=n/2;i++){
            if(vis[i]==1 && vis[n-i]==1 && i<=n-i) ans.push_back({i,n-i});
        }
        return ans;
    }
};