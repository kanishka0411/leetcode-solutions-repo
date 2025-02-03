class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int maxi=0;
        int inc_count=1;
        int dec_count=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc_count++;
                dec_count=1;
            }else if(nums[i]<nums[i-1]){
                dec_count++;
                inc_count=1;
            }else{
                inc_count=1;
                dec_count=1;
            }
            maxi=max(maxi,max(inc_count,dec_count));
        }
        return maxi;

    }
};