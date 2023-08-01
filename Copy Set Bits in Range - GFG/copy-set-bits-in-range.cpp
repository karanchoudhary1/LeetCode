//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        int ans=x;
        x=x>>(l-1);
        y=y>>(l-1);
        for(int i=l;i<=r;i++){
           if(y<=0) break;
           if(y&1){
               if(!(x&1)) ans+=pow(2,i-1);
           }
           x=x>>1;
           y=y>>1;
        }
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends