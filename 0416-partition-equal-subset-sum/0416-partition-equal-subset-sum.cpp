class Solution {
public:

    bool isPoss(vector<int>nums,int target,int n,vector<vector<int>>&t){
        if(target==0) return true;
        if(n==0) return false;
        if(t[n][target]!=-1) return t[n][target];
        if(target<nums[n-1]){
            return t[n][target]= isPoss(nums,target,n-1,t);
        }
        return t[n][target]=isPoss(nums,target-nums[n-1],n-1,t)|| isPoss(nums,target,n-1,t);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;
        vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
        return isPoss(nums,sum,n,t);
        
    }
};