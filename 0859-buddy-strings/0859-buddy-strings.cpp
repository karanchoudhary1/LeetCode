class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return 0;
        int cnt=0;
        int a=-1;
        int b=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                if(a==-1) a=i;
                else if(b==-1) b=i;
                else return 0;
            }
        }
        if(a==-1 && b==-1){
            sort(s.begin(),s.end());
            for(int i=1;i<s.length();i++){
                if(s[i]==s[i-1]) return 1;
            }
        }
        else if(a==-1 || b==-1) return 0;
        else {
            swap(s[a],s[b]);
            if(s==goal) return 1;
        }
        return 0;
    }
};