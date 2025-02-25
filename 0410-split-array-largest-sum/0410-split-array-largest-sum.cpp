class Solution {
public:

    int count(vector<int>&nums,int c){
        int n=nums.size();
        int split=1;
        int splitCount=0;
        for(int i=0;i<n;i++){
            if(splitCount+nums[i]<=c){
                splitCount+=nums[i]; 
            }else{
                split++;
                splitCount=nums[i];
            }
        }

        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        // for(int i=low;i<=high;i++){
        //     if(count(nums,i)==k){
        //         return i;
        //     }
        // }

        while(low<=high){
            int mid=low+(high-low)/2;
            int n=count(nums,mid);
            if(n>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return low;
    }
};