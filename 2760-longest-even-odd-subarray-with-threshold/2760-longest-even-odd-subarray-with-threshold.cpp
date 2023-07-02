class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1 || nums[i]>threshold) continue;
            int j;
            for( j=i+1;j<nums.size();j++){
                if(nums[j]%2!=nums[j-1]%2 && nums[j]<=threshold) continue;
                else break;
            }
            ans=max(ans,j-i);
            i=j-1;
        }
        return ans;
    }
};