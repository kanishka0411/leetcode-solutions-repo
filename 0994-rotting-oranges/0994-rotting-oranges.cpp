class Solution {
public:
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n) return false;
        if(c<0 || c>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
        int cnt=0;
        int time=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                auto it=q.front();
                q.pop();
                int row=it.first;
                int col=it.second;
                for(int i=0;i<4;i++){
                    int newrow=row+r[i];
                    int newcol=col+c[i];

                    if(isValid(newrow,newcol,n,m) && grid[newrow][newcol]==1){
                        q.push({newrow,newcol});
                        grid[newrow][newcol]=2;
                    }
                }
            }
            if(!q.empty()) time++;
        }
        if(total==cnt) return time;
        return -1;

    }
};