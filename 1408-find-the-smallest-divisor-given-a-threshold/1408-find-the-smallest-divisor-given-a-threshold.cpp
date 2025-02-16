class Solution {
public:

    int sumOfD(vector<int>&nums,int mid){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)(nums[i])/(double)(mid));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int st=1;
        int end=*max_element(nums.begin(),nums.end());
        while(st<=end){
            int mid=st+(end-st)/2;
            if(sumOfD(nums,mid)<=threshold){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;

    }
};