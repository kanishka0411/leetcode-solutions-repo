class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>ele(nums.begin(),nums.end());
        int maxLen=0;
        for(int num:nums){
            if(ele.find(num-1)==ele.end()){
                int currNum=num;
                int currLen=1;
                while(ele.find(currNum+1)!=ele.end()){
                    currLen++;
                    currNum++;
                }
                maxLen=max(maxLen,currLen);
            }
        }
        return maxLen;
    }
};