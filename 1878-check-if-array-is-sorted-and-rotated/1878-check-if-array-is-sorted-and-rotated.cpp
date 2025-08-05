class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int cnt=0;
        if(nums[st]<nums[end]) cnt++;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) cnt++;
        }
        return cnt<=1;
    }
};