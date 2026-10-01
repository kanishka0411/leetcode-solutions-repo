class Solution {
public:
    long long solve(vector<int>&piles,int b,int h){
        int n=piles.size();
        long long time=0;
        for(int i=0;i<n;i++){
            time+=ceil((double)piles[i]/b);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=*max_element(piles.begin(),piles.end());
        int st=1;
        int end=maxi;
        int ans=0;
        while(st<=end){
            int mid=(st+end)/2;
            long long bph=solve(piles,mid,h);
            if(bph<=h){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};