class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int mask,vector<int>& v,vector<int>& nums){
        if(i==nums.size()){
            if(mask==pow(2,nums.size())-1) ans.push_back(v);
            return;
        }
        f(i+1,mask,v,nums);
        if((mask&1<<i)==0){
            v.push_back(nums[i]);
            f(0,mask|1<<i,v,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        f(0,0,v,nums);
        return ans;
    }
};