class Solution {
public:
    void func(vector<int>&nums,set<vector<int>>&st,vector<int>temp,int i){
        int n=nums.size();
        if(i==n){
            st.insert(temp);
            return;
        }
        func(nums,st,temp,i+1);
        temp.push_back(nums[i]);
        func(nums,st,temp,i+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        set<vector<int>>st;
        func(nums,st,temp,0);
        return vector<vector<int>>(st.begin(),st.end());

    }
};