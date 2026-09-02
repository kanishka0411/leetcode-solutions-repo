class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        //row wise cumulative sum 
        for(int r=0;r<n;r++){
            for(int c=1;c<m;c++){
                matrix[r][c]+=matrix[r][c-1];
            }
        }

        int result=0;
        for(int st=0;st<m;st++){
            for(int c=st;c<m;c++){
                unordered_map<int,int>mpp;
                mpp[0]=1;
                int sum=0;
                for(int r=0;r<n;r++){
                    sum+=matrix[r][c]-(st>0?matrix[r][st-1]:0);
                    result+=mpp[sum-target];
                    mpp[sum]++;
                }
            }
        }
        return result;

    }
};