class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        int n=costs.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long ans=0;
        for(int i=0;i<can;i++){
            if(pq.size()==n) break;
            pq.push({costs[i],1});
            if(pq.size()==n) break;
            pq.push({costs[n-i-1],2});
        }
        int i=can;
        int j=n-can-1;
        while(k!=0){
            auto x=pq.top();
            pq.pop();
            ans+=x.first;
            if(x.second==1){
                if(i<=j){
                pq.push({costs[i],1});
                i++;
                }
            }
            else{
                if(i<=j){
                    pq.push({costs[j],2});
                    j--;
                }
            }
            k--;
        }
        return ans;
    }
};