class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=-1;
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                ans=i;
            }
        }
        return ans;
    }
};