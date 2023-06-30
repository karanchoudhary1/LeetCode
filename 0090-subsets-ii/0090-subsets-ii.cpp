class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,vector<int>& nums,vector<int> v){
        if(i==nums.size()) {
            ans.push_back(v); 
            return;
        }
        v.push_back(nums[i]);
        f(i+1,nums,v);
        v.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        f(i+1,nums,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         f(0,nums,{});
        return ans;
    }
};