//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        int m=1e9+7;
        vector<long long> ans;
        ans.push_back(1);
        ans.push_back(1);
        if(n==1) return {1};
        if(n==2) return ans;
        for(int i=2;i<n;i++){
            vector<long long> x;
            x.push_back(1);
            for(int i=0;i<ans.size()-1;i++){
                x.push_back((ans[i]+ans[i+1])%m);
            }
            x.push_back(1);
            ans=x;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends