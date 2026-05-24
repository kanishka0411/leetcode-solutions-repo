class Solution {
public:
    long long func(vector<int>&piles,int k){
        long long ans=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            ans+=ceil((double)piles[i]/(double)k);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int st=1;
        int end=maxi;
        while(st<=end){
            int mid=(st+end)/2;
            if(func(piles,mid)<=h){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;
    }
};