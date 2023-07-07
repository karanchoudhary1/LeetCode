class Solution {
public:
    bool solve(vector<int>& nums, int k,int limit){
        int t=1;
        int sum=0;
        for(auto i:nums){
            if(sum+i<=limit) sum+=i;
            else {
                t++;
                sum=i;
            }
        }
        if(t>k) return 0;
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int ans=INT_MAX;
        for(int it=0;it<n;++it) i=max(i,nums[it]), j+=nums[it];
        while(i<=j){
            int m=(i+j)/2;
            if(solve(nums,k,m)){
                ans=min(ans,m);
                j=m-1;

            }
            else i=m+1;
        }
        return i;
    }
};