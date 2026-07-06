class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n) return false;
        if(c<0 || c>=m) return false;
        return true;
    }
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int color,int inColor){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(isValid(nrow,ncol,n,m) && image[nrow][ncol]==inColor && ans[nrow][ncol]!=color){
                ans[nrow][ncol]=color;
                dfs(nrow,ncol,ans,image,color,inColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inColor=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(sr,sc,ans,image,color,inColor);
        return ans;
    }
};