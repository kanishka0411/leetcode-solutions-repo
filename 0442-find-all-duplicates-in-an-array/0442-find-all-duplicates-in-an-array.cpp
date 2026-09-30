class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.find(nums[i])!=st.end()) ans.push_back(nums[i]);
            else st.insert(nums[i]);
        }
        return ans;
    }
};