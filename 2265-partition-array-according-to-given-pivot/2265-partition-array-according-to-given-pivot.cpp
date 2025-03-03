class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>one;
        vector<int>two;
        vector<int>three;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                one.push_back(nums[i]);
            }
            if(nums[i]==pivot){
                two.push_back(nums[i]);
            }
            if(nums[i]>pivot){
                three.push_back(nums[i]);
            }
        }
        ans.insert(ans.end(),one.begin(),one.end());
        ans.insert(ans.end(),two.begin(),two.end());
        ans.insert(ans.end(),three.begin(),three.end());
        return ans;
    }
};