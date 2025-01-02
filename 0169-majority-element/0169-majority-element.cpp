class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                ele=nums[i];
            }else if(ele==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ele==nums[i]){
                cnt++;
            }
        }
        if(cnt>(n/2)){
            return ele;
        }

        return -1;
    }
};