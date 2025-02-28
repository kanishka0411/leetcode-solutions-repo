class Solution {
public:

    int findDays(vector<int>&weights,int cap){
        int n=weights.size();
        int load=0;
        int d=1;
        for(int i=0;i<n;i++){
            if(weights[i]+load<=cap){
                load+=weights[i];
            }else{
                load=weights[i];
                d++;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //--------------------------Brute----------------------------------------------
        // int n=weights.size();
        // int maxi=*max_element(weights.begin(),weights.end());
        // int sum=accumulate(weights.begin(),weights.end(),0);
        // for(int i=maxi;i<=sum;i++){
        //     if(findDays(weights,i)<=days){
        //         return i;
        //     }
        // }
        // return -1;

        //----------------------------Optimal--------------------------------------------

        int n=weights.size();
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int noOfDay=findDays(weights,mid);
            if(noOfDay>days){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;

    }
};