class Solution {
public:
vector<int>findNSE(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            ans[i]=!st.empty()?st.top():n;

            st.push(i);
        }
        return ans;
    }
    vector<int>findNGE(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }

            ans[i]=!st.empty()?st.top():n;

            st.push(i);
        }
        return ans;
    }
    vector<int>findPSE(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=nums[i];

            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            ans[i]=!st.empty()?st.top():-1;

            st.push(i);
        }
        return ans;
    }

    vector<int>findPGE(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }

            ans[i]=!st.empty()?st.top():-1;

            st.push(i);
        }

        return ans;
    }

    long long subarrayMax(vector<int>nums){
        int n=nums.size();
        long long sum=0;
        vector<int>pg=findPGE(nums);
        vector<int>ng=findNGE(nums);
        for(int i=0;i<n;i++){
            int left=i-pg[i];
            int right=ng[i]-i;

            long freq=1LL*left*right;
            long val=1LL*nums[i]*freq;

            sum+=val;
        }
        return sum;
    }

    long long subarrayMin(vector<int>nums){
        int n=nums.size();
        long long sum=0;
        vector<int>ps=findPSE(nums);
        vector<int>ns=findNSE(nums);
        for(int i=0;i<n;i++){
            int left=i-ps[i];
            int right=ns[i]-i;

            long long freq=1LL*left*right;
            long long val=1LL*nums[i]*freq;

            sum+=val;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subarrayMax(nums)-subarrayMin(nums);
    }
};