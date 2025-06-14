class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unsigned int xoro=0;
        for(int i=0;i<n;i++){
            xoro^=nums[i];
        }

        unsigned int rightSetBit=(xoro&(xoro-1))^xoro;
        int xor1=0;
        int xor2=0;
        for(int i=0;i<n;i++){
            if(nums[i]&rightSetBit){
                xor1^=nums[i];
            }else{
                xor2^=nums[i];
            }
        }

        return {xor1,xor2};
    }
};