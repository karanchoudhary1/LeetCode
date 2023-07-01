class Solution {
public:
    int f(int ind,vector<int>& v,vector<int>& cookies){
        if(ind==cookies.size()){
           int d=0;
            for(int i=0;i<v.size();i++){
                if(v[i]==0) return 1e9;
                d=max(d,v[i]);
            }
            return d;
        }
        int ans=1e9;
        for(int i=0;i<v.size();i++){
            v[i]+=cookies[ind];
            ans=min(f(ind+1,v,cookies),ans);
            v[i]-=cookies[ind];
         }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {       
        vector<int> v(k,0);
        return f(0,v,cookies);
    }
};