class Solution {
public:
    int ans=1e9;
    void f(int ind,vector<int>& v,vector<int>& cookies){
        if(ind==cookies.size()){
           int d=0;
            for(int i=0;i<v.size();i++){
                if(v[i]==0) return;
                d=max(d,v[i]);
            }
           ans=min(ans,d);
            return;
        }
        for(int i=0;i<v.size();i++){
            v[i]+=cookies[ind];
            f(ind+1,v,cookies);
            v[i]-=cookies[ind];
         }
    }
    int distributeCookies(vector<int>& cookies, int k) {       
        vector<int> v(k,0);
        f(0,v,cookies);
        return ans;
    }
};