class Solution {
public:

    bool have(int start,int end,vector<int>&bi){
        int st=0;
        int en=bi.size()-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(bi[mid]<start){
                st=mid+1;
            }else if(bi[mid]>end){
                en=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>bi;

        for(int i=1;i<n;i++){
            if(nums[i-1]%2==nums[i]%2){
                bi.push_back(i);
            }
        }

        vector<bool>res(m,false);
        for(int i=0;i<m;i++){
            int st=queries[i][0];
            int end=queries[i][1];

            bool hv=have(st+1,end,bi);
            if(hv==false){
                res[i]=true;
            }
        }

        return res;
    }
};