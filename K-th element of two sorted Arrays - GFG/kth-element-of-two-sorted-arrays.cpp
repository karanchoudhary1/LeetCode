//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool f(int mid,int nums1[],int nums2[],int n,int a,int b){
         int d=upper_bound(nums1,nums1+a,mid)-nums1;
         d+=upper_bound(nums2,nums2+b,mid)-nums2;
         if(d<=n) return 0;
        else return 1;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low=0;
        int high=INT_MAX;
               while(low<=high){
            int mid=low+(high-low)/2;
            bool x=f(mid,arr1,arr2,k-1,n,m);
            if(x==0) low=mid+1;
            else high=mid-1;
        }
      return low;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends