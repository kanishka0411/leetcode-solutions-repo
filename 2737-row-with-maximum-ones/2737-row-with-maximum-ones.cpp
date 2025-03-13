class Solution {
public:

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //-----------------------------Brute----------------------------------------------
        int n=mat.size();
        int m=mat[0].size();
        vector<int>res(2,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            if(cnt>maxi){
                maxi=cnt;
                res[0]=i;
                res[1]=maxi;
            }
        }
        return res;

        //----------------------------------Better----------------------------------------------
       


    }
};