class Solution {
public:
    bool f(vector<int>& nums,int mid){
        if(mid%2==1){
            if(nums[mid+1]==nums[mid]) return 0;
            else return 1;
        }
        else{
            if(nums[mid-1]==nums[mid]) return 0;
        }
        return 1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int low=1;
        int high=nums.size()-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            bool x=f(nums,mid);
            if(x==0) high=mid-1;
            else low=mid+1;
        }
        return nums[low];
    }
};