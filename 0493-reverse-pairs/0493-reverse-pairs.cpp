class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        int l=low;
        int r=mid+1;
        vector<int>temp;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }

        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }

        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int countPairs(vector<int>&nums,int low,int mid,int high){
        int r=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            while(r<=high && nums[i]>2*(1LL)*nums[r]) r++;
            cnt+=r-(mid+1);
        }
        return cnt;
    }
    int ms(vector<int>&nums,int low,int high){
        int cnt=0;
        if(low==high) return cnt;
        int mid=(low+high)/2;
        cnt+=ms(nums,low,mid);
        cnt+=ms(nums,mid+1,high);
        cnt+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return ms(nums,0,n-1);
    }
};