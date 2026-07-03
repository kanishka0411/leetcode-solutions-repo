class Solution {
public:
    void heapifyDown(vector<int>&nums,int ind,int last){
        int left=2*ind+1;
        int right=2*ind+2;
        int big=ind;
        if(left<=last && nums[left]>nums[big]) big=left;
        if(right<=last && nums[right]>nums[big]) big=right;

        if(big!=ind){
            swap(nums[big],nums[ind]);
            heapifyDown(nums,big,last);
        }
        return;
    }
    void buildMaxHeap(vector<int>&nums){
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapifyDown(nums,i,n-1);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        buildMaxHeap(nums);
        int last=n-1;
        while(k--){
            ans=nums[0];
            swap(nums[0],nums[last]);
            last--;
            heapifyDown(nums,0,last);
        }
        return ans;
        
    }
};