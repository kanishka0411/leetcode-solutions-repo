class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0;
        int j=n-1;
        int pos=n-1;
        while(i<=j){
            int sq1=nums[i]*nums[i];
            int sq2=nums[j]*nums[j];
            if(sq2>sq1){
                ans[pos]=sq2;
                j--;
            }else {
                ans[pos]=sq1;
                i++;
            }
            pos--;
        }
        return ans;
    }
};