class Solution {
public:
    long long find(vector<int>&piles,int num,int h){
        int n=piles.size();
        long long res=0;
        for(int i=0;i<n;i++){
            if(num>piles[i]) res+=1;
            else res+=ceil((double)piles[i]/num);
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=-1;
        int n=piles.size();
        int k=0;
        int maxi=*max_element(piles.begin(),piles.end());

        int st=1;
        int end=maxi;
        while(st<=end){
            int mid=(st+end)/2;
            long long val=find(piles,mid,h);
            if(val<=h){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};