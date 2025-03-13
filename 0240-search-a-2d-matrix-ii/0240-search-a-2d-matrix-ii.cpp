class Solution {
public:
    // bool bS(vector<int>arr,int target){
    //     int low=0;
    //     int high=arr.size()-1;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(arr[mid]==target){
    //             return true;
    //         }

    //         if(arr[mid]<target){
    //             low=mid+1;
    //         }else{
    //             high=mid-1;
    //         }
    //     }

    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        //----------------------------BETTER-----------------------------------------
        // int low=0;
        // int high=m-1;
        // for(int i=0;i<n;i++){
        //     int flag=bS(matrix[i],target);
        //     if(flag) return true;
        // }

        // return false;



        //------------------------------OPTIMAL----------------------------------------
        int low=0;
        int high=m-1;
        while(low<n && high>=0){
            if(matrix[low][high]==target) return true;
            else if(matrix[low][high]<target) low++;
            else high--;
        }

        return false;

    }
};