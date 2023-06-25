class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==1) return -1;
        q.push({1,{0,0}});
        while(q.size()!=0){
           // cout<<"s";
            int i=q.front().second.first;
            int j=q.front().second.second;
            if(grid[i][j]==1){
                q.pop();
                continue;
            }
            int res=q.front().first;
            if(i==grid.size()-1 && j==grid.size()-1) return res;
            grid[i][j]=1;
            q.pop();
            for(int cx=-1;cx<=1;cx++){
                for(int dx=-1;dx<=1;dx++){
                    if(i+cx>=0 && i+cx<grid.size() && j+dx>=0 && j+dx<grid.size() && grid[i+cx][j+dx]==0){
                        q.push({res+1,{i+cx,j+dx}});
                    }
                }
            }
        }
        return -1;
    }
};