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
        for(int ind=i;ind<nums.size();ind++){
            if(ind==nums.size()-1){
                f(ind+1,nums,v);
            }
            else if(nums[ind]==nums[ind+1]) continue;
            else {
                f(ind+1,nums,v);
                break;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         f(0,nums,{});
        return ans;
    }
};