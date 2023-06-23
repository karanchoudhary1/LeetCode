class Solution {
public:
     int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>> v(nums.size());
        int ans=2;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int dif=nums[j]-nums[i];
                int cnt=2;
                if(v[i].count(dif)) v[j][dif]=v[i][dif]+1;
                else v[j][dif]=2;
                ans=max(ans,v[j][dif]);
        }
        }
        return ans;
    }
};