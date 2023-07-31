class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,string& s1,string& s2){
        if(i==s1.length()){
            int sum=0;
            for(int z=j;z<s2.length();z++) sum+=s2[z];
            return sum;
        }
        if(j==s2.length()){
            int sum=0;
            for(int z=i;z<s1.length();z++) sum+=s1[z];
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a=s1[i]+f(i+1,j,s1,s2);
        int b=s2[j]+f(i,j+1,s1,s2);
        int c=1e9;
        if(s1[i]==s2[j]) c=f(i+1,j+1,s1,s2);
        return dp[i][j]=min(a,min(b,c));
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,s1,s2);
    }
};