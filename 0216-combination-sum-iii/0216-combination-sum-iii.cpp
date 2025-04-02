class Solution {
public:
    void func(int k,int n,vector<vector<int>>&ans,vector<int>&temp,int ind){
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<=9;i++){
            temp.push_back(i);
            func(k,n-i,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(k,n,ans,temp,1);
        return ans;
    }
};