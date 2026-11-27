class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]) st.pop();
            if(st.empty()) mpp[i%n]=-1;
            else mpp[i%n]=st.top();

            st.push(nums[i%n]);

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[i]);
        }

        return ans;
    }
};