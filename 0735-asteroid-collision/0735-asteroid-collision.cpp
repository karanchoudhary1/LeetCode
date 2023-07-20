class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> st;
        st.push(v[0]);
        for(int i=1;i<v.size();i++){
            if(st.size()==0 || st.top()<0 || v[i]>0) {
                st.push(v[i]);
                continue;
            }
            while(st.top()>0 && v[i]<0){
                 if(st.top()>abs(v[i])){
                     break;
                 }
                else if(st.top()==abs(v[i])){
                     st.pop();
                     break;
                }
                else{
                    st.pop();
                    if(st.size()==0 || st.top()<0){
                        st.push(v[i]);
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};