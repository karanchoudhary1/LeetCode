class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans=0;
        stack<long long> s;
        for(int i=0;i<tokens.size();i++){
            if(s.size()==0){
                long long int d=stoi(tokens[i]);
                s.push(d);
                continue;
            }
                if(tokens[i]=="*"){
                    long long int y=s.top();
                    s.pop();
                    long long int x=s.top();
                    s.pop();
                    s.push(x*y);
                } 
                else if(tokens[i]=="+") {
                     long long int y=s.top();
                    s.pop();
                    long long int x=s.top();
                    s.pop();
                    s.push(x+y);
                }
                else if(tokens[i]=="-") {
                     long long int y=s.top();
                    s.pop();
                    long long int x=s.top();
                    s.pop();
                    s.push(x-y);
                }
                else if(tokens[i]=="/"){
                     long long int y=s.top();
                    s.pop();
                    long long int x=s.top();
                    s.pop();
                    s.push(x/y);
                }
             else s.push(stoi(tokens[i]));
            }
        return s.top();
    }
};