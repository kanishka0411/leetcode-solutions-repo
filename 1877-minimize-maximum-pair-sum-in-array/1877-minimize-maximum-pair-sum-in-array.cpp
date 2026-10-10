class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=n-1;
        vector<int>final;
        while(l<r){
            int sum=nums[l]+nums[r];
            final.push_back(sum);
            l++;
            r--;
        }
        int maxi=*max_element(final.begin(),final.end());
        return maxi;
    }
};