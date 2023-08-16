class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++) pq.push({nums[i],i});
        int i=k;
        vector<int> ans;
        ans.push_back(pq.top().first);
        while(i<nums.size()){
            pq.push({nums[i],i});
            while(pq.top().second<=i-k) pq.pop();
            ans.push_back(pq.top().first);
            i++;
        }
        return ans;
    }
};