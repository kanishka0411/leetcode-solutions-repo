class Solution {
public:
    void func(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int ind,vector<bool>&vis){
        int n=nums.size();
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1] && !vis[i-1]) continue;
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i]=true;
                func(nums,ans,temp,ind+1,vis);
                temp.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>vis(n,false);
        func(nums,ans,temp,0,vis);
        return ans;
    }
};