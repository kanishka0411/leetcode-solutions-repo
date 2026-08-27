class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>check;
        for(int i=0;i<n;i++){
            if(check.find(nums[i])!=check.end()) return true;
            else check.insert(nums[i]);
        }
        return false;
    }
};