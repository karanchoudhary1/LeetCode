class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int,int> m;
        int ans=0;
        //sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            ans=max(ans,m[arr[i]]);
            if(m[arr[i]+diff]<m[arr[i]]+1)
            m[arr[i]+diff]=m[arr[i]]+1;
        }
        return ans+1;
    }
};