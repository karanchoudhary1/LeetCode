class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int prev1=-1;
        int prev2=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) continue;
            else{
                if(prev1==-1 && prev2==-1) ans=max(ans,i);
                else ans=max(ans,i-prev2-2);
                prev2=prev1;
                prev1=i;   
            }
        }
        ans=max(n-prev2-2,ans);
        if(prev1==-1 || prev2==-1) return nums.size()-1;
        return ans;
    }
};