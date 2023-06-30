//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxi=0;
        vector<pair<int,int>> v;
        // your code here
        for(int i=0;i<n;i++){
            v.push_back({arr[i].profit,arr[i].dead});
            maxi=max(maxi,arr[i].dead);
        }
        vector<int> x(maxi+1,0);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int cnt=v[i].second;
            if(x[cnt]==0){
                x[cnt]=v[i].first;
            }
            else{
                while(cnt!=0 && x[cnt]!=0) cnt--;
                if(cnt!=0) x[cnt]=v[i].first;
            }
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<x.size();i++) {
            if(x[i]!=0) cnt++;
            ans+=x[i];
        }
        return {cnt,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends