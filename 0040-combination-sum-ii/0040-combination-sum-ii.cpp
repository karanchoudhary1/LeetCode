class Solution {
public:
    void f(int i,int tar,vector<int> v,vector<int>& nums,vector<vector<int>>& ans){
        if(tar<=0){
            if(tar==0) ans.push_back(v);
            return;
        }
        if(i==nums.size()) return;
        v.push_back(nums[i]);
        f(i+1,tar-nums[i],v,nums,ans);
        v.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        f(i+1,tar,v,nums,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        f(0,target,{},candidates,ans);
        return ans;
    }
};