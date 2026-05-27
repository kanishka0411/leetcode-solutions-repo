class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxLen=0;
        int l=0;
        int r=0;
        int zeroCnt=0;
        while(r<n){
            if(nums[r]==0) zeroCnt++;
            if(zeroCnt>k){
                if(nums[l]==0) zeroCnt--;
                l++;
            }
            if(zeroCnt<=k){
                int len=r-l+1;
                maxLen=max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
    
};