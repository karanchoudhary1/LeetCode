class Solution {
public:
    int dp[1001][27][27];
    int f(int ind,char st,char end,vector<string>& words){
        if(ind==words.size()) return 0;
        if(dp[ind][st-'a'][end-'a']!=-1) return dp[ind][st-'a'][end-'a'];
       int a=1e9;
        int b=1e9;
        string s=words[ind];
        char i=s[0];
        char j=s[s.size()-1];
        if(i==end) a=f(ind+1,st,j,words)+s.length()-1;
        else a=f(ind+1,st,j,words)+s.length();
        if(st==j) b=f(ind+1,i,end,words)+s.length()-1;
        else b=f(ind+1,i,end,words)+s.length();
        return dp[ind][st-'a'][end-'a']=min(a,b);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        return words[0].length() +f(1,words[0][0],words[0][words[0].size()-1],words);
    }
};