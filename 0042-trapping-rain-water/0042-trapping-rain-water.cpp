class Solution {
public:
    int trap(vector<int>& v) {
        vector<int> pg;
        vector<int> ng(v.size(),0);
        ng[v.size()-1]=-1;
        int maxi=v[0];
        for(int i=0;i<v.size();i++){
            if(i==0){
                pg.push_back(-1);
            }
            else{
                if(v[i]>=maxi){
                    pg.push_back(-1);
                    maxi=max(v[i],maxi);
                }
                else pg.push_back(maxi);
            }
        }
        maxi=v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
                if(v[i]>=maxi){
                    ng[i]=(-1);
                   maxi=v[i];
                }
                else ng[i]=maxi;
        }
        int ans=0;
        for(int i=1;i<v.size()-1;i++){
            if(pg[i]!=-1 && ng[i]!=-1){
                int d=min(pg[i],ng[i]);
                d-=v[i];
                ans+=d;
            }
        }
        return ans;
    }
};