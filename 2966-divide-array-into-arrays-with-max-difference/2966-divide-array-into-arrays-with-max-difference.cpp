class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> x;
        sort(nums.begin(),nums.end());
        int mini=1e9;
        for(int i=0;i<nums.size();i++){
            if((i+1)%3==0){
                if((nums[i]-mini)<=k){
                    x.push_back(nums[i]);
                    ans.push_back(x);
                    x.clear();
                }
                else return {};
                mini=1e9;
            }
            else{
                mini=min(mini,nums[i]);
                x.push_back(nums[i]);
            }
        }
        return ans;
    }
};