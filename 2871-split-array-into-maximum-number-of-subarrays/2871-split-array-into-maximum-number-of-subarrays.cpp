class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++) ans=ans&nums[i];
        if(ans!=0) return 1; 
        int res=0;
        bool f1=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==0) {
                res++;
                i++;
            }
            else break;
        }
        if(i==nums.size()) return res;
        int curr=nums[i];
        i++;
        while(i<nums.size()){
            if(nums[i]==0){
                res++;
                i++;
                curr=-1;
                continue;
            }
            if(curr==-1) curr=nums[i];
            else curr=curr&nums[i];
            if(curr==0){
                res++;
                curr=-1;
            }
            i++;
        }
        if(curr==0 && nums[nums.size()-1]!=0) res++;
        return res;
    }
};