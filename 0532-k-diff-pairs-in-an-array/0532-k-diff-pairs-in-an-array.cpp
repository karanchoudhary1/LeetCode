class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans=0;
        if(k==0){
            int i=1;
            while(i<nums.size()){
                if(nums[i]==nums[i-1]) ans++;
                else{
                    i++;
                    continue;
                }
                i++;
                while(i<nums.size() && nums[i]==nums[i-1]) i++;
            }
            return ans;
        }
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        int i=0;
        while(i<nums.size()){
            int x=nums[i]+k;
            if(s.find(x)!=s.end()) ans++;
            i++;
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};