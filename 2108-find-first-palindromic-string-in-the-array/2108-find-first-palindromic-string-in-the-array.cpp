class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            int d=words[i].length();
            bool f1=0;
            for(int j=0;j<d/2;j++){
                if(words[i][j]!=words[i][words[i].length()-j-1]) f1=1;
            }
            if(f1==0) return words[i];
        }
        return "";
    }
};