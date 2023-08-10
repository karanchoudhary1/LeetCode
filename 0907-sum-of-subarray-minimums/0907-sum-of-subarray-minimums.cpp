class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prev;
        prev.push_back(-1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<arr.size();i++){
            while(st.size()!=0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) prev.push_back(-1);
            else prev.push_back(st.top());
            st.push(i);
        }
        vector<int> nex;
        nex.push_back(arr.size());
        while(st.size()!=0) st.pop();
        st.push(arr.size()-1);
        for(int i=arr.size()-2;i>=0;i--){
            while(st.size()!=0 && arr[st.top()]>arr[i]) st.pop();
            if(st.size()==0) nex.push_back(arr.size());
            else nex.push_back(st.top());
            st.push(i);
        }
        reverse(nex.begin(),nex.end());
        long long ans=0;
        int m=1e9+7;
        for(int i=0;i<arr.size();i++){
            int d1=nex[i]-i;
            int d2=i-prev[i];
            int tot=d1*d2;
            ans+=(long long)arr[i]*(long long)tot;
            ans=ans%m;
        }
        return ans%m;
    }
};