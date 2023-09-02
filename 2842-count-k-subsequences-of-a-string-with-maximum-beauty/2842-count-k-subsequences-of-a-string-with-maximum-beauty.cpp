class Solution {
public:
    int mod = 1e9+7;
    map<pair<pair<long long,long long>,long long>,int>dp;
    long long ans(vector<int>p,int i,int max_beauty,int k)
    {
        if(i == p.size())
        {
            if(max_beauty == 0&& k == 0)
                return 1;
            return 0;
        }
        if(dp.find({{i,k},max_beauty}) != dp.end())
            return dp[{{i,k},max_beauty}]%mod;
        long long nontake = ans(p,i+1,max_beauty,k);
        long long take = 0;
        if(p[i]>0 && max_beauty>=p[i]&&k>0)
        take = (p[i]%mod*ans(p,i+1,max_beauty-p[i],k-1)%mod)%mod;
return  dp[{{i,k},max_beauty}] = (take%mod+nontake%mod)%mod;        
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k>26)
            return 0;
        vector<int>p(26,0);
        for(int i = 0;i<s.length();i++)
            p[s[i]-'a']++;
        
        vector<int>temp = p;
        sort(temp.begin(),temp.end());
    int x = k,max_beauty = 0,l = 25;
        while(x--)
        {
            max_beauty+=temp[l];
            l--;
        }
        return ans(p,0,max_beauty,k)%mod;
    }
};