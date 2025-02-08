class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
       int n=nums.size();
       int l=0;
       long currSum=0;
       int result=0;
       for(int r=0;r<n;r++){
        long target=nums[r];
        currSum+=nums[r];

        if((r-l+1)*target-currSum>k){
            currSum-=nums[l];
            l++;
        }
        result=max(result,r-l+1);
       }
       return result;
    }
};