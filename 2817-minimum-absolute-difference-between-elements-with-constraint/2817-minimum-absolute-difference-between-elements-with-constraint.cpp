class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int dif) {
        if(dif==0) return 0;
        set<int> s;
        int ans=1e9;
        for(int i=dif;i<nums.size();i++){
            s.insert(nums[i-dif]);
             auto it=s.lower_bound(nums[i]);
            if(it!=s.end()) ans=min(ans,*it-nums[i]);
        }
        s.clear();
        for(int i=nums.size()-dif-1;i>=0;i--){
            s.insert(nums[i+dif]);
             auto it=s.lower_bound(nums[i]);
            if(it!=s.end()) ans=min(ans,*it-nums[i]);
        }
        return ans;
    }
};