class Solution {
public:
    bool f(int i,vector<vector<int>>& v,vector<int>& vis){
          if(vis[i]==-1) return 0;
          if(vis[i]==1) return 1;
          vis[i]=1;
          for(auto x:v[i]){
              if(f(x,v,vis)==1) return 1;
          }
        vis[i]=-1;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(vis[i]==0){
                bool x=f(i,graph,vis);
                if(x==0) ans.push_back(i);
            }
            else if(vis[i]==-1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};