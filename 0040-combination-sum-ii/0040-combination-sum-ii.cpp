class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int tar,vector<int> v,vector<int>& nums){
        if(tar<=0){
            if(tar==0) ans.push_back(v);
            return;
        }
        if(i==nums.size()) return;
        v.push_back(nums[i]);
        f(i+1,tar-nums[i],v,nums);
        v.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        f(i+1,tar,v,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(0,target,{},candidates);
        return ans;
    }
};