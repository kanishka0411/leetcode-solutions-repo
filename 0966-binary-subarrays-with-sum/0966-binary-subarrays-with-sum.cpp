class Solution {
public: 
    int atMost(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int count=0;
        int n=nums.size();
        int sum=0;
        int r=0;
        int l=0;
        while(r<n){
            sum+=(nums[r]%2);
            while(sum>goal){
                sum-=(nums[l]%2);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};