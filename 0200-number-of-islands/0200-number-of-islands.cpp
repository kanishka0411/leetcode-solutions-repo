class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        if(row<0 || row>=n) return false;
        if(col<0 || col>=m) return false;

        return true;
    }
    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
  
            for(int k=0;k<4;k++){
                int newrow=row+r[k];
                int newcol=col+c[k];
                if(isValid(newrow,newcol,n,m) && grid[newrow][newcol]=='1' && !vis[newrow][newcol]){
                    vis[newrow][newcol]=true;
                    q.push({newrow,newcol});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};