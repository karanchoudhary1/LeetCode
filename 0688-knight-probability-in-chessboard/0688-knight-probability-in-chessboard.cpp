class Solution {
public:
    double dp[26][26][101];
    double f(int i,int j,int n,int k){
        if(i<0 || j<0 || j>=n || i>=n) return 0;
        if(k==0) return 1;
        if(dp[i][j][k]!=-1.0) return dp[i][j][k];
    double ans=0;
    ans+=f(i-2,j-1,n,k-1);
    ans+=f(i-2,j+1,n,k-1);
    ans+=f(i-1,j-2,n,k-1);
    ans+=f(i+1,j-2,n,k-1);
    ans+=f(i+1,j+2,n,k-1);
    ans+=f(i-1,j+2,n,k-1);
    ans+=f(i+2,j-1,n,k-1);
    ans+=f(i+2,j+1,n,k-1);
        return dp[i][j][k]=ans;
     }
    double knightProbability(int n, int k, int row, int column) {
        if(k==0) return 1;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        double x=f(row,column,n,k);
        double z=pow(8,k);
        return x/z;
    }
};