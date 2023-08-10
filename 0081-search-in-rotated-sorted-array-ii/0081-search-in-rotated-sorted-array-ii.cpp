class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int hi=n-1;
        while(low<=hi){
            int mid=(low+hi)/2;
            if(nums[mid]==target) return 1;
            if(nums[low]==nums[mid] && nums[mid]==nums[hi]){
                low++;
                hi--;
            }
            else if(nums[mid]>=nums[low]){
                 if(target>=nums[low] && target<=nums[mid]) hi=mid-1;
                 else low=mid+1;
             }
            else{
                if(target>=nums[mid] && target<=nums[hi]) low=mid+1;
                else hi=mid-1;
            }
        }
        return 0;
    }
};