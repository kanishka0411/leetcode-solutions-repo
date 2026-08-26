class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>copy=board;
        vector<int>row={1,0,-1,0,1,-1,-1,1};
        vector<int>col={0,-1,0,1,1,-1,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cell=board[i][j];
                int live=0;
                for(int k=0;k<8;k++){
                    int r=i+row[k];
                    int c=j+col[k];
                    if(r>=0 && r<n && c>=0 && c<m && copy[r][c]==1) live++;
                }
                if(copy[i][j]==1 && live<2) board[i][j]=0;
                if(copy[i][j]==1 && live>3) board[i][j]=0;
                if(copy[i][j]==0 && live==3) board[i][j]=1;
            }
        }
    }
};