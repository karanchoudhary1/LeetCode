class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k==1) return s.length();
      unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int ans=0;
        int st=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(m[s[i]]<k){
                int a=st;
                int b=i-1;
                while(a<=b){
                    if(mp[s[b]]<k){
                        mp[s[b]]--;
                        m[s[b]]--;
                        b--;
                    }
                    else{
                        mp[s[a]]--;
                        m[s[a]]--;
                        a++;
                    }
                    bool f1=0;
            for(auto x:mp){
                if(x.second<k && x.second>0){
                    f1=1;
                }
            }       
                    if(f1==0) ans=max(ans,b-a+1);
                }
                st=i+1;
                mp.clear();
                continue;
            }  
            mp[s[i]]++;
            bool f1=0;
            for(auto x:mp){
                if(x.second<k){
                    f1=1;
                    break;
                }
            }
            if(f1==0) ans=max(ans,i-st+1);
        }
           return ans;
    }
};