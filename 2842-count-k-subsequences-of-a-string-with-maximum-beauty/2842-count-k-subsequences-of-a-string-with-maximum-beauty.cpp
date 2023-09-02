class Solution {
public:
    int mod=1e9+7;
    map<pair<pair<long long,long long>,long long>,int> dp;
    long long int f(int i,int k,long long int maxl,string& s,vector<int>& v){
        if(i==s.length()){
            if(k==0 && maxl==0) return 1;
            return 0;
        }
       if(dp.find({{i,k},maxl}) != dp.end())
            return dp[{{i,k},maxl}]%mod;
        long long int nt=f(i+1,k,maxl,s,v);
        long long int tk=0;
        if(maxl-v[s[i]-'a']>=0 && k>0){
            tk=(v[s[i]-'a']*(f(i+1,k-1,maxl-v[s[i]-'a'],s,v)%mod))%mod;
        }
        return dp[{{i,k},maxl}]=(tk%mod+nt%mod)%mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k>26) return 0;
        vector<int> cnt(26,0);
        for(int i=0;i<s.length();i++) cnt[s[i]-'a']++;
        vector<int> v=cnt;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        long long int maxl=0;
        for(int i=0;i<k;i++) maxl+=v[i];
        unordered_set<char> st;
        for(int i=0;i<s.length();i++) st.insert(s[i]);
        string s1;
        for(auto x:st) s1+=x;
        return f(0,k,maxl,s1,cnt)%mod;
    }
};