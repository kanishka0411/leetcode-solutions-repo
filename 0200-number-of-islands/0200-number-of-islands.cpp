class Solution {
public:
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n) return false;
        if(c<0 || c>=m) return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
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

                if(isValid(newrow,newcol,n,m) && !vis[newrow][newcol] && grid[newrow][newcol]=='1'){
                    vis[newrow][newcol]=true;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
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