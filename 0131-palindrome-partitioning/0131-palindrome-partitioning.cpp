class Solution {
public:
    bool z(int st,int en,string s){
         while(st<en){
             if(s[st]!=s[en]) return 0;
             st++;
             en--;
         }
        return 1;
    }
    vector<vector<string>> ans;
    void f(int st,int i,string s,vector<string> v){
           if(i==s.length()){
               if(st==i)
               ans.push_back(v);
               return;
           }
          if(z(st,i,s)==1){
            string x=s.substr(st,i-st+1);
              v.push_back(x);
              f(i+1,i+1,s,v);
              v.pop_back();
          }
        f(st,i+1,s,v);
    }
    
    vector<vector<string>> partition(string s) {
         f(0,0,s,{});
        return ans;
    }
};