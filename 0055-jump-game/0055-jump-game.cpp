class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxindx=0;
        for(int i=0;i<n;i++){
            if(i>maxindx) return false;
            maxindx=max(maxindx,nums[i]+i);
        }
        return true;
    }
};