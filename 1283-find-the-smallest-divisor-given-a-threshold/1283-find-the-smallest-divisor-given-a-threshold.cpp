class Solution {
public:
    int div(int mid,vector<int>&nums){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int st=1;
        int high=*max_element(nums.begin(),nums.end());
        while(st<=high){
            int mid=(st+high)/2;
            int val=div(mid,nums);
            if(val<=threshold) high=mid-1;
            else st=mid+1;
        }
        return st;
    }
};