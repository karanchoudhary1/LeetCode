class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end());
        int a;
        int b;
        for(int i=0;i<intervals.size();i++){
            if(i==0){
             a=intervals[i][0];
         b=intervals[i][1];
            }
            else {
                a=intervals[i-1][0];
                b=intervals[i-1][1];
            }
            while(i<intervals.size() && intervals[i][0]<=b){
                b=max(b,intervals[i][1]);
                i++;
            } 
            ans.push_back({a,b});
        }
        if(ans[ans.size()-1][1]<intervals[intervals.size()-1][0]) ans.push_back(intervals[intervals.size()-1]);
        return ans;
    }
};