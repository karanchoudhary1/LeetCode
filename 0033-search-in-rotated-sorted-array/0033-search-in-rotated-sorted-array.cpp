class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int hi=nums.size()-1;
        if(nums[0]==target) return 0;
        if(nums[nums.size()-1]==target) return nums.size()-1;
        while(low<=hi){
            int mid=(low+hi)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[low]){
                if(target>=nums[low] && target<=nums[mid]) hi=mid-1;
                else low=mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[hi]) low=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};