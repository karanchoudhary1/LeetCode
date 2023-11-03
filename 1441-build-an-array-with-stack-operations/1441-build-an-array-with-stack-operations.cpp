class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int curr=1;
        for(int i=0;i<target.size();i++){
            while(curr!=target[i]){
                curr++;
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            curr++;
        }
        return ans;
    }
};