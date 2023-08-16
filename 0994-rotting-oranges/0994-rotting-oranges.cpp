class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        bool f2=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({0,{i,j}});
                if(grid[i][j]==1) f2=1;
            }
        }
        int ans=0;
        while(q.size()!=0){
            int i=q.front().second.first;
            int j=q.front().second.second;
            int res=q.front().first;
            q.pop();
            ans=max(ans,res);
            if(i-1>=0 && grid[i-1][j]==1){
                q.push({res+1,{i-1,j}});
                grid[i-1][j]=2;
            }
            if(j-1>=0 && grid[i][j-1]==1){
                q.push({res+1,{i,j-1}});
                grid[i][j-1]=2;
            }
            if(i+1<grid.size() && grid[i+1][j]==1){
                q.push({res+1,{i+1,j}});
                grid[i+1][j]=2;
            }
            if(j+1<grid[0].size() && grid[i][j+1]==1){
                q.push({res+1,{i,j+1}});
                grid[i][j+1]=2;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};