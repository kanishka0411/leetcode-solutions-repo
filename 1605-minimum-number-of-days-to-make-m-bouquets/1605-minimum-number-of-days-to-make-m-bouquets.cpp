class Solution {
public:

    bool isPossible(vector<int>&nums,int day,int m,int k){
        int n=nums.size();
        int cnt=0;
        int nOfB=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=day){
                cnt++;
            }else{
                nOfB+=cnt/k;
                cnt=0;
            }
        }
        nOfB+=cnt/k;
        return nOfB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val = 1LL * m * k;  

        if(val>n){
            return -1;
        }
        int ans=-1;
        int st=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isPossible(bloomDay,mid,m,k)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};