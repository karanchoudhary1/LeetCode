class Solution {
public:
    int f(int i,int st,string s,unordered_set<string>& sest,vector<vector<int>>& dp){
        if(i==s.length()-1){
            string sx=s.substr(st);
            if(sest.find(sx)!=sest.end()) return 0;
            else return s.length()-st;
        }
        if(dp[i][st]!=-1) return dp[i][st];
        string x=s.substr(st,i-st+1);
        int a=1e9;
        int b=1e9;
        int c=1e9;
        if(sest.find(x)!=sest.end()) a=f(i+1,i+1,s,sest,dp);
        b=i-st+1+f(i+1,i+1,s,sest,dp);
        c=f(i+1,st,s,sest,dp);
        return dp[i][st]=min(a,min(b,c));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        vector<vector<int>> dp(51,vector<int>(51,-1));
        for(int i=0;i<dictionary.size();i++) st.insert(dictionary[i]);
        return f(0,0,s,st,dp);
    }
};