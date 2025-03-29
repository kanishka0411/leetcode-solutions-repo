class Solution {
public:
    void combi(vector<int>&candidates,vector<int>&temp,int i,vector<vector<int>>&ans,int target){
        int n=candidates.size();
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n||target<0){
            return;
        }

        temp.push_back(candidates[i]);
        combi(candidates,temp,i,ans,target-candidates[i]);
        temp.pop_back();
        combi(candidates,temp,i+1,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        combi(candidates,temp,0,ans,target);
        return ans;
    }
};