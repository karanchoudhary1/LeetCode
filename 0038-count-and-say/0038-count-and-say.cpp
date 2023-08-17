class Solution {
public:
    string countAndSay(int n) {
        string ans="11";
        if(n==1) return "1";
        if(n==2) return ans;
        for(int z=3;z<=n;z++){
            string newx="";
            int cnt=0;
            for(int i=0;i<ans.length()-1;i++){
                if(ans[i]==ans[i+1]) cnt++;
                else{
                    cnt++;
                    newx+=to_string(cnt);
                    newx+=ans[i];
                    cnt=0;
                }
            }
            if(ans[ans.length()-1]==ans[ans.length()-2]){
                cnt++;
                newx+=to_string(cnt);
                newx+=ans[ans.length()-1];
            }
            else{
                newx+="1";
                newx+=ans[ans.length()-1];
            }
            ans=newx;
        }
        return ans;
    }
};