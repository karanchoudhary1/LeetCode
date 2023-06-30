class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,vector<int> v,int tar,vector<int>& nums){
        if(tar<=0){
            if(tar==0) ans.push_back(v);
            return;
        }
        if(i==nums.size()) return;
        f(i+1,v,tar,nums);
        v.push_back(nums[i]);
        f(i,v,tar-nums[i],nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         f(0,{},target,candidates);
        return ans;
    }
};