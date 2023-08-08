//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
         int ans=0;
        map<pair<int,int>,int> m;
        for(int i=0;i<n;i++){
            int b=__gcd(num[i],den[i]);
            num[i]=num[i]/b;
            den[i]=den[i]/b;
            ans+=m[{den[i]-num[i],den[i]}];
            m[{num[i],den[i]}]++;
        }
         return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends