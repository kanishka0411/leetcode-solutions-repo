class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r=sum%k;
            if(r<0) r+=k;
            cnt+=mpp[r];
            mpp[r]++;

        }
        return cnt;
    }
};