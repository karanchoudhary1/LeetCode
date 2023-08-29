class Solution {
public:
    int bestClosingTime(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='Y') cnt++;
        }
        int ans=cnt;
        int prev=0;
        int res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='Y') cnt--;
            else prev++;
            if(cnt+prev<ans){
                ans=cnt+prev;
                res=i+1;
            }
        }
        return res;
    }
};