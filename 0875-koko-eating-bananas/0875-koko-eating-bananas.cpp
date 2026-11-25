class Solution {
public:
    long long calc(vector<int>&piles,int h,int num){
        long long res=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            res+=ceil((double)piles[i]/num);
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int st=1;
        int end=maxi;
        int ans=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(calc(piles,h,mid)<=h){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
       
        return ans;
    }
};