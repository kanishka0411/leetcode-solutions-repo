class Solution {
public:
    bool canEatAll(vector<int>&nums,int h,int mid){
        long long time=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            time+=(nums[i]+mid-1)/mid;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long st=1;
        long long end=*max_element(piles.begin(),piles.end());
        int ans=end;
        while(st<=end){
            long long  mid=st+(end-st)/2;
            if(canEatAll(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};