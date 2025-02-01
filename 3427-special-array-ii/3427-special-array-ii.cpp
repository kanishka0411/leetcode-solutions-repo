class Solution {
public:

    int binSearch(vector<int>&vi,int start,int end){
        int st=0;
        int en=vi.size()-1;

        while(st<=en){
            int mid=st+(en-st)/2;
            if(vi[mid]<start){
                st=mid+1;
            }else if(vi[mid]>end){
                en=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        int n=nums.size();

        vector<int>vi;
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                vi.push_back(i);
            }
        }

        vector<bool>res(m,false);

        for(int i=0;i<m;i++){
            int st=queries[i][0];
            int end=queries[i][1];
            
            bool haveVI=binSearch(vi,st+1,end);

            if(haveVI==false){
                res[i]=true;
            }
        }

        return res;

    }
};