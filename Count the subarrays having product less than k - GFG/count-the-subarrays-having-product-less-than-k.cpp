//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        long long ans=0;
        long long sum=1;
        int st=0;
        for(int i=0;i<n;i++){
            if(st==n) break;
            sum*=nums[i];
            while(st<n && sum>=k){
                if(i>st)
                ans+=i-st;
                sum/=nums[st];
                st++;
            }
        }
         while(st<nums.size()){
            ans+=nums.size()-st;
            st++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends