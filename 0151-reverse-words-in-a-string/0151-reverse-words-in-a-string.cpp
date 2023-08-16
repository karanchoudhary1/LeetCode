class Solution {
public:
    string reverseWords(string s) {
        string curr="";
        string ans="";
        for(int i=0;i<s.length();i++){
            if(curr=="" && s[i]==' ') continue;
            if(s[i]==' '){
                reverse(curr.begin(),curr.end());
                ans+=curr;
                ans+=" ";
                curr="";
            }
            else curr.push_back(s[i]);
        }
        reverse(curr.begin(),curr.end());
        ans+=curr;
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.length()&&ans[i]==' ') i++;
        return ans.substr(i);
    }
};