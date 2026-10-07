class Solution {
public:
    int findDays(vector<int>&weights,int cap){
        int n=weights.size();
        int d=1;
        int load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i]<=cap){
                load+=weights[i];
            }else{
                d++;
                load=weights[i];
            }
        }
        return d;
    } 
   int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=accumulate(weights.begin(),weights.end(),0);
        int maxi=*max_element(weights.begin(),weights.end());
        int st=maxi;
        int end=sum;
        int ans=0;
        while(st<=end){
            int mid=(st+end)/2;
            if(findDays(weights,mid)<=days){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        
        return ans;
    }
};