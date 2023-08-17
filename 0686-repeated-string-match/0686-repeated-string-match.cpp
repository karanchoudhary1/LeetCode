class Solution {
public:
    int m=1e6;
    int f(int x,int s){
        long long int ans=1;
        for(int i=0;i<s;i++){
            ans=ans*x;
            ans=ans%m;
        }
        return ans;
    }
    int repeatedStringMatch(string a, string b) {
        int cnt=1;
        string x=a;
        while(a.length()<=b.length()){
            if(a.length()==b.length() && a==b) return cnt;
            cnt++;
            a+=x;
            //cout<<a<<endl;            
        }
        long long int hash=0;
        long long int comp=0;
        for(int i=0;i<b.length();i++){
            hash+=f(2,i)*(a[i]-'a'+1);
            comp+=f(2,i)*(b[i]-'a'+1);
            hash%=m;
            comp%=m;
        }
        long long int s=hash;
        if(hash==comp) return cnt;
        for(int i=b.length();i<a.length();i++){
            hash+=f(2,b.length())*(a[i]-'a'+1);
            hash-=(a[i-b.length()]-'a'+1);
            hash=hash/2;
            if(hash==comp) return cnt;
        }
        cnt++;
        a+=x;
        hash=s;
        for(int i=b.length();i<a.length();i++){
            hash+=f(2,b.length())*(a[i]-'a'+1);
            hash-=(a[i-b.length()]-'a'+1);
            hash=hash/2;
            if(hash==comp) return cnt;
        }
        return -1;
    }
};