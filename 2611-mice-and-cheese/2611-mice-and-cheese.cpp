class Solution {
public:
    int miceAndCheese(vector<int>& v1, vector<int>& v2, int k) {
        int n=v1.size();
        vector<pair<int,int>> diff;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++) diff.push_back({v1[i]-v2[i],i});
        sort(diff.begin(),diff.end());
        reverse(diff.begin(),diff.end());
        int ans=0;
        for(int i=0;i<k;i++){
                ans+=v1[diff[i].second];
                vis[diff[i].second]=1;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) ans+=v2[i];
        }
        return ans;
    }
};