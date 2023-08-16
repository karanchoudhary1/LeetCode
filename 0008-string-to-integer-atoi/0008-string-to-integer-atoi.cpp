class Solution {
public:
    long long xt=pow(2,31);
    long long y=xt-1;
    int myAtoi(string s) {
        //return 0;
        int i=0;
        while(i<s.length() && s[i]==' ') i++;
        bool f1=0;
        if(i!=s.length() && s[i]=='-'){
            f1=1;
            i++;
         }
         else{
             if(i==s.length()) return 0;
             if(s[i]=='+') i++;
         }
        while(i<s.length() && s[i]=='0') i++;
        if(i==s.length() || s[i]<48 || s[i]>57) return 0;
        string x="";
        while(i<s.length() && s[i]>=48 && s[i]<=57){
            x+=s[i];
            i++;
        }
        if(x.length()>=12){
            if(f1==0) return y;
            return xt*-1;
        }
        long long int ans=0;
        int q=0;
        for(int j=x.length()-1;j>=0;j--){
            ans+=(x[j]-48)*pow(10,q);
            q++;
            if(f1==0 && ans>y){
                return y;
            }
            if(f1==1 && ans>xt){
                return xt*-1;
            }
        }
        if(f1==1){
             return ans*-1;
        }
        return ans;
    }
};