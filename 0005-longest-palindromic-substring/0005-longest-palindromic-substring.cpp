class Solution {
public:
    
    string longestPalindrome(string s) {
        int res=0;
        int n=s.length();
        string ans="";
       for(int i=0;i<s.length();i++){
           for(int j=s.length()-1;j>=i;j--){
               if(s[i]==s[j]){
                   int leng=j-i+1;
                   if(leng%2==0){
                       string x=s.substr(i,leng/2);
                       string y=s.substr(i+leng/2,leng/2);
                       reverse(y.begin(),y.end());
                       if(x==y && leng>res){
                           res=leng;
                           ans=s.substr(i,leng);
                       }
                   }
                   else{
                       string x=s.substr(i,leng/2);
                       string y=s.substr(i+leng/2+1,leng/2);
                       reverse(y.begin(),y.end());
                       if(x==y && leng>res){
                           res=leng;
                           ans=s.substr(i,leng);
                       }
                   }
               }
           }
       }
        // if(res==0){
        //     string x="";
        //     x+=s[0];
        //     return x;
        // }
       return ans;
    }
};