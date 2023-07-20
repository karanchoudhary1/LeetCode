class Solution {
public:
    int dp[100001][3];
    int f(int i,int cho,vector<int>& nums1,vector<int>& nums2){
        if(i==nums1.size()) return 0;
        if(dp[i][cho+1]!=-1) return dp[i][cho+1];
        int a=1e9;
        int b=1e9;
        if(cho==-1){
            a=f(i+1,0,nums1,nums2);
            b=1+f(i+1,1,nums1,nums2);
        }
        else if(cho==0){
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]) a=f(i+1,0,nums1,nums2);
            if(nums2[i]>nums1[i-1] && nums1[i]>nums2[i-1]) b=1+f(i+1,1,nums1,nums2);
        }
        else{
            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) a=f(i+1,0,nums1,nums2);
            if(nums2[i]>nums2[i-1] && nums1[i]>nums1[i-1]) b=1+f(i+1,1,nums1,nums2);
        }
        return dp[i][cho+1]=min(a,b);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,nums1,nums2);
    }
};