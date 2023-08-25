class Solution {
public:
    int dp[101][101][201];
    bool f(int i,int j,int k,string& s1,string& s2,string& s3){
        if(k==s3.length()){
          if(i==s1.length() && j==s2.length()) return 1;
            return 0;
        } 
         if(i==s1.length()){
             return f(i,j+1,k+1,s1,s2,s3) && s2[j]==s3[k];
         }
        if(j==s2.length()){
            return f(i+1,j,k+1,s1,s2,s3) && s1[i]==s3[k];
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(s3[k]!=s1[i] && s3[k]!=s2[j]) return dp[i][j][k]=0;
        bool a=0;
        bool b=0;
        if(s1[i]==s3[k]) a=f(i+1,j,k+1,s1,s2,s3);
        if(s2[j]==s3[k]) b=f(i,j+1,k+1,s1,s2,s3);
        return dp[i][j][k]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,s1,s2,s3);
    }
};