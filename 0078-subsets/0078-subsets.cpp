class Solution {
public:
    void func(vector<int>&nums,vector<vector<int>>&ans,int i,vector<int>temp){
        int n=nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        } 
        func(nums,ans,i+1,temp);
        temp.push_back(nums[i]);
        func(nums,ans,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        // ans.push_back(temp);
        func(nums,ans,0,temp);

        return ans;
        
    }
};