class Solution {
public:
    bool f(int mid,vector<int>& nums1,vector<int>& nums2,int n){
         int d=upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
         d+=upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
         if(d<=n) return 0;
        else return 1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool f1=0;
        int n=nums1.size()+nums2.size();
        if(n%2==0) f1=1;
        n=n/2;
        
        int low=-1e6;
        int high=1e6;
        while(low<=high){
            int mid=(low+high)/2;
            bool x=f(mid,nums1,nums2,n);
            if(x==0) low=mid+1;
            else high=mid-1;
        }
        int ans=low;
        if(f1==1){
            int low=-1e6;
        int high=1e6;
            n--;
        while(low<=high){
            int mid=(low+high)/2;
            bool x=f(mid,nums1,nums2,n);
            if(x==0) low=mid+1;
            else high=mid-1;
        }
        ans+=low;
        }
        if(f1==0)
        return ans;
        double z=(double)ans/2;
        return z;
    }
};