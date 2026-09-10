class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int cnt=0;
        int psum=0;
        for(int i=0;i<n;i++){
            psum+=nums[i];
            cnt+= mpp[psum-k];
            mpp[psum]++;
        }
        return cnt;
    }
};