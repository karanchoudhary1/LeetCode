class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1e9;
        int cs=0;
        int st=0;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            if(cs>=target){
                while(cs>=target){
                    ans=min(ans,i-st+1);
                    cs-=nums[st];
                    st++;
                }
            }
        }
        if(ans==1e9) return 0;
        return ans;
    }
};