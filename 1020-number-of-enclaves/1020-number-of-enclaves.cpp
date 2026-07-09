class Solution {
public:
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n) return false;
        if(c<0 || c>=m) return false;

        return true;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=0;i<4;i++){
                int newrow=row+r[i];
                int newcol=col+c[i];

                if(isValid(newrow,newcol,n,m) && !vis[newrow][newcol] && grid[newrow][newcol]==1){
                    vis[newrow][newcol]=true;
                    q.push({newrow,newcol});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};