class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        bool up=true;
        for(int d=0;d<n+m-1;d++){
            if(!up){
                for(int i=0;i<n;i++){
                   int j=d-i;
                   if((j>=0 && j<m)){
                    ans.push_back(mat[i][j]);
                   }
                }
            }else{
                for(int i=n-1;i>=0;i--){
                    int j=d-i;
                    if(j>=0 && j<m){
                        ans.push_back(mat[i][j]);
                    }
                }
            }
            
            
            up=!up;
        }
        return ans;
    }
};