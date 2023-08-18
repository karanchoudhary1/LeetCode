class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> v(n,vector<int>(n,0));
        vector<int> cnt(n,0);
        for(int i=0;i<roads.size();i++){
               v[roads[i][0]][roads[i][1]]=1;
            v[roads[i][1]][roads[i][0]]=1;
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=cnt[i]+cnt[j];
                if(v[i][j]==1) curr--;
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};