class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=1;
        int hi=arr.size()-2;
        while(low<=hi){
            int mid=(low+hi)/2;
             if(arr[mid+1]>arr[mid] && arr[mid-1]<arr[mid]) low=mid+1;
            else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]) hi=mid-1;
            else return mid;
        }
        return 0;
    }
};