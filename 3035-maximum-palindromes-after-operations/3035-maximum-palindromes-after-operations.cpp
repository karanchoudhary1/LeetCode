class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> v(26,0);
        vector<int> x;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                v[words[i][j]-'a']++;
            }
            x.push_back(words[i].length());
        }
        sort(x.begin(),x.end());
        int ans=0;
        for(int i=0;i<x.size();i++){
            int d=x[i];
            int di=d;
            for(int z=0;z<26;z++){
                if(v[z]==0) continue;
                if(v[z]%2==0){
                    if(d%2==0){
                        if(v[z]>=d){
                            v[z]-=d;
                            d=0;
                        }
                        else{
                            d-=v[z];
                            v[z]=0;
                        }
                    }
                    else{
                        if(v[z]>=d){
                            v[z]-=d;
                            v[z]++;
                            d=1;
                        }
                        else{
                            d-=v[z];
                            v[z]=0;
                        }
                    }
                }
                else{
                    if(d%2==0){
                        if(v[z]>=d){
                            v[z]-=d;
                            d=0;
                        }
                        else{
                            d-=v[z];
                            d++;
                            v[z]=1;
                        }
                    }
                    else{
                        if(v[z]>=d){
                            v[z]-=d;
                            d=0;
                        }
                        else{
                            d-=v[z];
                            v[z]=0;
                        }
                    }
                }
                int df=-1;
                if(d==1){
                    for(int q=0;q<26;q++){
                        if(v[q]%2==1){
                            v[q]--;
                            d=0;
                            break;
                        }
                        if(v[q]!=0) df=q;
                    }
                    if(d==1 && df!=-1){
                        d=0;
                        v[df]--;
                    }
                }
                 if(d==0) break;
            }
            if(d==0) ans++;
            else{
                v[0]+=di-d;
            }
        }
        return ans;
    }
};