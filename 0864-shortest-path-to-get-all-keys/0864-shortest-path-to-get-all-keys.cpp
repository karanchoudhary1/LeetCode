class Solution {
public:
     int dx[4] = {1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int shortestPathAllKeys(vector<string>& grid) {
        pair<int,int> st;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        int k=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].length();j++){
                if(grid[i][j]=='@') st={i,j};
                if(grid[i][j]>='a' && grid[i][j]<='s') k++;
            }
        }
        int chk=pow(2,k)-1;
        // i j k mask
        set<vector<int>> stx;
        pq.push({0,{st.first,st.second,k,0}});
        while(pq.size()!=0){
            int ans=pq.top().first;
            vector<int> v=pq.top().second;
            pq.pop();
            if(stx.find(v)!=stx.end()) continue;
            else stx.insert(v);
            int i=v[0];
            int j=v[1];
            int k=v[2];
            int mask=v[3];
            if(mask==chk) return ans;
            //grid[i][j]='#';
            for(int h=0;h<4;h++){
                int ni=dx[h]+i;
                int nj=dy[h]+j;
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size()){
                    if(grid[ni][nj]=='#') continue;
                    if(grid[ni][nj]>='a' && grid[ni][nj]<='o'){
                        int d=grid[ni][nj]-'a';
                        if((mask & (1<<d)) == 0)
                        pq.push({ans+1,{ni,nj,k-1,mask|1<<d}});
                        else pq.push({ans+1,{ni,nj,k,mask|1<<d}});
                    }
                    else if(grid[ni][nj]>='A' && grid[ni][nj]<='O'){
                        int d=grid[ni][nj]-'A';
                        if((mask & (1<<d)) == 0)continue;
                        else pq.push({ans+1,{ni,nj,k,mask}});
                    }
                 else pq.push({ans+1,{ni,nj,k,mask}});
                }
            }
        }
        return -1;
    }
};