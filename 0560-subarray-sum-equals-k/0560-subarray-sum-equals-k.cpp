class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int prefix=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int rem=prefix-k;
            count+=mpp[rem];
            mpp[prefix]+=1;

        }
        return count;
    }
};