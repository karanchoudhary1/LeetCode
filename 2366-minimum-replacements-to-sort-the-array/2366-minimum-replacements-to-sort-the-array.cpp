class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int mini=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=mini){
                mini=nums[i];
                continue;
            }
            int parts=nums[i]/mini;
            if((nums[i]%mini)!=0) parts++;
            ans+=parts-1;
             mini=min(mini,nums[i]/parts);
        }
        return ans;
    }
};