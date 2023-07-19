class Solution {
public:
    static const bool mySort(vector<int> &a, vector<int> &b) {
			return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& events) {
            sort(events.begin(), events.end(), mySort);
            int ans=0;
        int st=events[0][1];
        for(int i=1;i<events.size();i++){
            if(events[i][0]<st){
                ans++;
            }
            else{
                st=events[i][1];
            }
        }
       return ans;
    }
};