class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        if(nums[end]>nums[st] || n==1){
            return nums[st];
        }
        while(st<=end){
            int mid=st+(end-st)/2;
            if(mid<n-1 && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[mid]<nums[st]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
        
    }
};