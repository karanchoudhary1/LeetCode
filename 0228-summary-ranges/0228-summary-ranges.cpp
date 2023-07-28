class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return {};
        string s=to_string(nums[0]);
        if(nums.size()==1){
            ans.push_back(s);
            return ans;
        }
        int prev=0;
        s="";
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) continue;
            if(prev==i-1){
                s=to_string(nums[prev]);
                ans.push_back(s);
                prev=i;
            }
            else{
                s=to_string(nums[prev]);
                s+="->";
                s+=to_string(nums[i-1]);
                ans.push_back(s);
                prev=i;
            }
            s="";
        }
        if(prev==nums.size()-1) s=to_string(nums[prev]);
        else{
            s=to_string(nums[prev]);
            s+="->";
            s+=to_string(nums[nums.size()-1]);
        }
        ans.push_back(s);
        return ans;
    }
};