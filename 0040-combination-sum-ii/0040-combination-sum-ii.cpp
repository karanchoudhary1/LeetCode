class Solution {
public: 
    void f(int index,vector<int>&ds,int target,vector<int> &candidates,vector<vector<int>> &ans){
       if(target<=0){
           if(target==0)
           {
               ans.push_back(ds);
           }
            return;
 }
        if(index==candidates.size()){
            return;
}
       
        ds.push_back(candidates[index]);
        f(index+1,ds,target-candidates[index],candidates,ans);
        ds.pop_back();
        
        int j;
        
        for(j=index+1; j<candidates.size(); j++)
        {
            if(candidates[j]!=candidates[index])
                break;
        }
        
        f(j,ds,target,candidates,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int> ds;
        
        f(0,ds,target,candidates,ans);
        return ans;
    }
};