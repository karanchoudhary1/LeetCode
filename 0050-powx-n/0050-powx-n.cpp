class Solution {
public:
    double myPow(double x, int q) {
        long long n=(long long)q;
        long long d=0;
        if(n==0) return 1;
        double ans=x;
        if(n==-1) return 1/ans;
        if(n==1) return ans;
        if(n<0){
            n=abs(n);
            d++;
            ans=1/x;
            while(d<n){
                ans*=ans;
                d*=2;
            }
            for(long long int i=n;i<d;i++) ans*=x;
        }
        else{
            d++;
            while(d<n){
                ans*=ans;
                d*=2;
            }
            for(long long int i=n;i<d;i++) ans/=x;
        }
        return ans;
    }
};