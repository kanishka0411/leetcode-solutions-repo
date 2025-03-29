class Solution {
public:

    void func(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&temp,int i,int target){
        int n=candidates.size();
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n || target<0){
            return;
        }

        temp.push_back(candidates[i]);
        func(candidates,ans,temp,i+1,target-candidates[i]);
        temp.pop_back();

        for(int j=i+1;j<n;j++){
            if(candidates[j]!=candidates[i]){
                func(candidates,ans,temp,j,target);
                break;
            }
        }

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>temp;
        func(candidates,ans,temp,0,target);
        return ans;
        
    }
};