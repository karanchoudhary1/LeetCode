class Solution {
public:
    int vis[10001];
    double f(int st,int end,vector<pair<int,double>>adj[]){
        priority_queue<pair<double,int>> pq;
        pq.push({1,st});
        while(pq.size()!=0){
             int node=pq.top().second;
            double dis=pq.top().first;
            pq.pop();
            if(node==end) return dis;
            if(vis[node]==1) continue;
            else vis[node]=1;
            for(auto x:adj[node]){
                pq.push({dis*x.second,x.first});
            }
    }
        return 0;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});
        }
        memset(vis,0,sizeof(vis));
        return f(start,end,adj);
    }
};