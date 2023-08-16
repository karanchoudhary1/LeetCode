class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_set<string> m;
        string x;
        for(int i=0;i<strs[0].length();i++){
            x+=strs[0][i];
            m.insert(x);
        }
        x="";
        int ans=1e9;
        for(int i=1;i<strs.size();i++){
            int cnt=0;
            for(int j=0;j<strs[i].length();j++){
                x+=strs[i][j];
                if(m.find(x)!=m.end()){
                    cnt++;
                }
                else break;
            }
            x="";
            ans=min(ans,cnt);
        }
        return strs[0].substr(0,ans);
    }
};