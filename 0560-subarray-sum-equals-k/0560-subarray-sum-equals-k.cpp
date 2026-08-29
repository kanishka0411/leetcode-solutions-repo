class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>seen;
        seen[0]=1;
        int prefix=0;
        int cnt=0;
        for(auto x:nums){
            prefix+=x;
            cnt+=seen[prefix-k];
            seen[prefix]++;
        }
        return cnt;
        

    }
};