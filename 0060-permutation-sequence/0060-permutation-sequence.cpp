class Solution {
public:
    int fact(int n){
        int ans=1;
        for(int i=2;i<=n;i++) ans=ans*i;
        return ans;
    }
    string ans;
    int vis[10];
    void f(int n,int k){
        if(n==1 || k==0){
            for(int i=1;i<=9;i++){
                if(vis[i]==0) {
                    ans+='0'+i;
                    break;
                }
            }
            return;
        }
        int d=fact(n-1);
        if(d>k){
            for(int i=1;i<10;i++){
                if(vis[i]==0){
                    ans+='0'+i;
                    vis[i]=1;
                    f(n-1,k);
                    break;
                }
            }
        }
        else{
            int z=k/d;
            if(k%d==0) z--;
            int q=z;
            for(int i=1;i<=9;i++){
                if(vis[i]==1) continue;
                if(z==0){
                    vis[i]=1;
                    ans+='0'+i;
                    f(n-1,k-q*d);
                    break;
                }
                z--;
            }
        }
    }
    string getPermutation(int n, int k) {
        memset(vis,0,sizeof(vis));
        f(n,k);
        return ans;
    }
};