class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>ans;
       deque<int>dq;
       for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=(k-1)){
                ans.push_back(nums[dq.front()]);
            }
       }
       
       return ans;
      
    }
}; 

/*
for (int i = 0; i < nums.size(); ++i) {
            // Remove out-of-window indices
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Record max if window is complete
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

*/ 
