class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) q.push({0,{i,j}});
            }
        }
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
        while(q.size()!=0){
            int res=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            if(vis[i][j]==1){
                q.pop();
                continue;
            }
            else vis[i][j]=1;
            mat[i][j]=res;
            q.pop();
            if(i-1>=0 && mat[i-1][j]==1){
                q.push({res+1,{i-1,j}});
            }
            if(j-1>=0 && mat[i][j-1]==1){
                q.push({res+1,{i,j-1}});
            }
            if(i+1<mat.size() && mat[i+1][j]==1) q.push({res+1,{i+1,j}});
            if(j+1<mat[0].size() && mat[i][j+1]==1) q.push({res+1,{i,j+1}});
        }
        return mat;
    }
};