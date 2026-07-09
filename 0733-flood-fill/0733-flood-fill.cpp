class Solution {
public:
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n) return false;
        if(c<0 || c>=m) return false;
        return true;
    }
    void bfs(vector<vector<int>>&image,int sr,int sc,vector<vector<int>>&ans,int color,int iniColor){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        ans[sr][sc]=color;
        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int row=it.first;
            int col=it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=row+r[i];
                int newcol=col+c[i];

                if(isValid(newrow,newcol,n,m) && ans[newrow][newcol]!=color && image[newrow][newcol]==iniColor){
                    ans[newrow][newcol]=color;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
        bfs(image,sr,sc,ans,color,iniColor);
        return ans;
    }
};