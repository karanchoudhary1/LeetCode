class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> m;
        m["I"]=1;
        m["V"]=5;
        m["X"]=10;
        m["L"]=50;
        m["C"]=100;
        m["D"]=500;
        m["M"]=1000;
        m["IV"]=4;
        m["IX"]=9;
        m["XL"]=40;
        m["XC"]=90;
        m["CD"]=400;
        m["CM"]=900;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1){
                string x;
                x.push_back(s[i]);
                ans+=m[x];
                break;
            }
            string x="";
            x.push_back(s[i]);
            x.push_back(s[i+1]);
            if(m[x]!=0){
                ans+=m[x];
                i++;
            }
            else{
                string x;
                x.push_back(s[i]);
                ans+=m[x];
            }
        }
        return ans;
    }
};