class Solution {
public:
    int atmost(vector<int>&nums ,int k,int n){
        map<int,int>mpp;
        int l=0;
        int r=0;
        int cnt=0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atmost(nums,k,n)-atmost(nums,k-1,n);
        
    }
};