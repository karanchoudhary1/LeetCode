//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]=0 || A[X][Y]==0) return -1;
        queue<pair<int,pair<int,int>>> pq;
        int dx1[4]={0,0,1,-1};
        int dx2[4]={1,-1,0,0};
        vector<vector<int>> dis(N,vector<int>(M,1e9));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(pq.size()!=0){
            auto it=pq.front();
            pq.pop();
            int d=it.first;
            pair<int,int> we={X,Y};
            if(it.second==we) return d;
            for(int i=0;i<4;i++){
                int nr=it.second.first+dx1[i];
                int nc=it.second.second+dx2[i];
                if(nr>=0 && nc>=0 && nr<N && nc<M && A[nr][nc]==1 && dis[nr][nc]>dis[it.second.first][it.second.second]+1){
                    dis[nr][nc]=dis[it.second.first][it.second.second]+1;
                    pq.push({d+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends