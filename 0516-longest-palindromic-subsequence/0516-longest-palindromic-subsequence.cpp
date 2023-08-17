class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,string& s,string& d){
        if(i==s.length() || j==d.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=f(i+1,j,s,d);
        int b=f(i,j+1,s,d);
        if(s[i]==d[j]){
            return dp[i][j]=f(i+1,j+1,s,d)+1;
        }
        return dp[i][j]=max(a,b);
    }
    int longestPalindromeSubseq(string s) {
        string d=s;
        memset(dp,-1,sizeof(dp));
        reverse(s.begin(),s.end());
        return f(0,0,s,d);
    }
};