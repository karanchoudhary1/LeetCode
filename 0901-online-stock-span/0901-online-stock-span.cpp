class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
        if(st.size()==0){
            st.push({price,1});
            return 1;
        }
        else{
            int ans=0;
            while(st.size()!=0 && st.top().first<=price){
                ans+=st.top().second;
                st.pop();
            }
            ans++;
            st.push({price,ans});
            return ans;
        }
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */