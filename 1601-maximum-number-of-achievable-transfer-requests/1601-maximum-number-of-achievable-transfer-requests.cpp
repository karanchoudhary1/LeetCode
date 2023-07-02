class Solution {
public:
    int f(int i,vector<int>& v,vector<vector<int>>& req){
        if(i==req.size()){
            for(int i=0;i<v.size();i++){
                if(v[i]!=0) return INT_MIN;
            }
            return 0;
        }
        int a=f(i+1,v,req);
        v[req[i][0]]--;
        v[req[i][1]]++;
        int b=f(i+1,v,req)+1;
        v[req[i][0]]++;
        v[req[i][1]]--;
        return max(a,b);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(21,0);
        return f(0,v,requests);
    }
};