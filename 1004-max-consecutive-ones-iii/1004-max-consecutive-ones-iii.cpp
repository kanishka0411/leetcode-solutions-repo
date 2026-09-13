class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt1=0;
        int cnt0=0;
        int maxlen=0;
        while(r<n){
            if(nums[r]==1) cnt1++;
            if(nums[r]==0) cnt0++;
            while(cnt0>k){
                if(nums[l]==0) cnt0--;
                l++;
            }
            if(cnt0<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};