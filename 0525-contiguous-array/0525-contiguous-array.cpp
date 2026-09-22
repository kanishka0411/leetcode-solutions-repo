class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int sum=0;
        int best=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum)!=mpp.end()){
                best=max(best,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
        return best;

    }
};