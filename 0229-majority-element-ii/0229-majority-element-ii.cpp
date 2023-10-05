class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=-2345734;
        int n2=-2345734;
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
            else if(c1==0) {
                n1=nums[i];
                c1++;
            }
            else if(c2==0){
                n2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1) cnt1++;
            if(nums[i]==n2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>(double)(nums.size())/3) ans.push_back(n1);
        if(cnt2>(double)(nums.size())/3) ans.push_back(n2);
        return ans;
    }
};