class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch){
                return false;
            }
        }

        for(int i=0;i<9;i++){
            if(board[i][col]==ch){
                return false;
            }
        }
        int startRow=3*(row/3);
        int startCol=3*(col/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[startRow+i][startCol+j]==ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board,row,col,ch)){
                            board[row][col]=ch;
                            if(solve(board)) return true;
                            board[row][col]='.';
                        }
                        

                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        solve(board);
    }
};