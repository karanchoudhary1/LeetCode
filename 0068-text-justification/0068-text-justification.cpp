class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        int prev=0;
        int sp=0;
        int pl=0;
        string s;
        while(i<words.size()){
            if(pl+sp+words[i].length()<=maxWidth){
                pl+=words[i].length();
                i++;
                sp++;
                continue;
            }
            //sp--;
            sp=maxWidth-pl;
            if(i-prev==1){
               s+=words[prev];
                int n=maxWidth-s.length();
                for(int i=0;i<n;i++) s+=' ';
                ans.push_back(s);
                
            }
            else{
            int a=i-prev-1;
            int b=sp%a;
            int c=sp/a;
                //cout<<c<<endl;
            for(int z=prev;z<i;z++){
                s+=words[z];
                if(z==i-1) break;
                for(int we=0;we<c;we++) s+=" ";
                if(b>0) s+=' ';
                b--;
            }
                ans.push_back(s);
            }
            s="";
            prev=i;
            sp=0;
            pl=0;
        }
        sp=maxWidth-pl;
        cout<<sp<<endl;
        for(int i=prev;i<words.size();i++){
            s+=words[i];
            if(i==words.size()-1) break;
            sp--;
            s+=' ';
        }
        for(int i=0;i<sp;i++) s+=' ';
        ans.push_back(s);
       return ans;
    }
};