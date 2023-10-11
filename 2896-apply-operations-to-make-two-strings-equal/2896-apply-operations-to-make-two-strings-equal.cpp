class Solution {
public:
    int dp[501][2];
    int f(int i,int j,bool f1,string& s1,string& s2,int x){
         if(i==s1.length()-1){
             if(f1==1){
                 if(s1[i]==s2[j]) return 1e6;
                 return 0;
             }
             if(s1[i]==s2[j]) return 0;
             return 1e6;
         }
        if(dp[i][f1]!=-1) return dp[i][f1];
         if(s1[i]==s2[j]) return dp[i][f1]=f(i+1,j+1,f1,s1,s2,x); 
         if(s1[i+1]=='0') s1[i+1]='1';
        else s1[i+1]='0';
        int a=1+f(i+1,j+1,f1,s1,s2,x);
         if(s1[i+1]=='0') s1[i+1]='1';
        else s1[i+1]='0';
        int b;
        if(f1==0){
            b=x+f(i+1,j+1,1,s1,s2,x);
        }
        else b=f(i+1,j+1,0,s1,s2,x);
        return min(a,b);
    }
    int minOperations(string s1, string s2, int x) {
        memset(dp,-1,sizeof(dp));
        int ans= f(0,0,0,s1,s2,x);
        if(ans>=1e6) return -1;
        return ans;
    }
};