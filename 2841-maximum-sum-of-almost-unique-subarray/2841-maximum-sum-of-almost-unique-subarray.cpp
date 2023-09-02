class Solution {
public:
    long long maxSum(vector<int>& nums, int siz, int k) {
        long long ans=0;
        long long sum=0;
        if(k>nums.size()) return 0;
        map<int,int> m;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
            sum+=nums[i];
        }
        int j=k;
        while(j<nums.size()){
            if(m.size()>=siz) ans=max(ans,sum);
            m[nums[j-k]]--;
            sum-=nums[j-k];
            if(m[nums[j-k]]==0) m.erase(nums[j-k]);
            m[nums[j]]++;
            sum+=nums[j];
            j++;
        }
        if(m.size()>=siz) ans=max(ans,sum);
        return ans;
    }
};