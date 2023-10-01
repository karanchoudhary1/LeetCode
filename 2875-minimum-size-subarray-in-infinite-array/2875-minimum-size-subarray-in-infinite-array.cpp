class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        long long int sum=0;
       for(int i=0;i<nums.size();i++){
           sum+=nums[i];
       }
        if(target%sum==0) return target/sum*n;
        map<long long int,int> m;
        if(sum>target){
            for(int i=0;i<n;i++) nums.push_back(nums[i]);
            int ans=1e9;
            long long int s=0;
            int j=0;
            for(int i=0;i<nums.size();i++){
                s+=nums[i];
                while(s>target) {
                    s-=nums[j];
                    j++;
                }
                if(s==target) ans=min(ans,i-j+1);
            }
            if(ans==1e9) return -1;
            return ans;
        }
        else{
            int ans=1e9;
            long long int s=0;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt++;
                s+=nums[i];
                m[s]=cnt;
            }
            s=0;
            for(int i=n-1;i>=0;i--){
                s+=nums[i];
                long long d=target-s;
                if(m.find(d%sum)!=m.end()){
                    ans=min(ans,n-i+(int)(m[d%sum]+(d/sum)*n));
                }
                if(d%sum==0){
                    ans=min(ans,(int)(n-i+((d/sum)*n)));
                }
            }
            if(ans==1e9) return -1;
            return ans;
        }
        return -1;
    }
};