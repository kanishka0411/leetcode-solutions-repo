class Solution {
public:

    bool canWePlace(vector<int>&nums,int dist,int cows){
        int n=nums.size();
        int cntCows=1;
        int last=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-last>=dist){
                cntCows++;
                last=nums[i];
            }
            if(cntCows>=cows) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int st=1;
        int end=position[n-1]-position[0];
        while(st<=end){
            int mid=st+(end-st)/2;
            if(canWePlace(position,mid,m)){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return end;
    }
};