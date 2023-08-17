class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i=0;
        int j=0;
        while(1>0){
            string num1="0";
            string num2="0";
            while(i<s1.length()){
                if(s1[i]=='.'){
                    i++;
                    break;
                }
                else num1+=s1[i];
                i++;
            }
            while(j<s2.length()){
                if(s2[j]=='.'){
                    j++;
                    break;
                }
                else num2+=s2[j];
                j++;
            }
            long long a=stoi(num1);
            long long b=stoi(num2);
            if(a>b) return 1;
            if(b>a) return -1;
            if(i==s1.length() && j==s2.length()) return 0;
        }
        return 1;
    }
};