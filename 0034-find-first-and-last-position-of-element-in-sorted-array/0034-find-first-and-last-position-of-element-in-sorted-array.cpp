class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n=nums.size();
        int st=0;
        int end=n-1;
        int first=-1;
        int last=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        st=0;
        end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                last=mid;
                st=mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        ans[0]=first;
        ans[1]=last;
        return ans;
    }
};