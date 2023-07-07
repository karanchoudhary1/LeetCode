class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans=0;
        int x=0;
        int st=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='F'){
                x++;
                while(x>k){
                    if(s[st]=='F') x--;
                    st++;
                }
            }
            ans=max(ans,i-st+1);
        }
         x=0;
         st=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='T'){
                x++;
                while(x>k){
                    if(s[st]=='T') x--;
                    st++;
                }
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};