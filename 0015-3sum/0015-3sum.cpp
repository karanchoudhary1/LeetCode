class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int a=i+1;
                int b=nums.size()-1;
                while(a<b){
                if(nums[i]+nums[a]+nums[b]==0){
                    ans.push_back({nums[i],nums[a],nums[b]});
                    a++;
                    b--;
                }
                else if(nums[i]+nums[a]+nums[b]>0) b--;
                else a++;
                while(a<n && a!=i+1 && nums[a]==nums[a-1]) a++;
                while(b>=0 && b!=n-1 && nums[b]==nums[b+1]) b--;
            }
        }
    }
        return ans;
    }
};