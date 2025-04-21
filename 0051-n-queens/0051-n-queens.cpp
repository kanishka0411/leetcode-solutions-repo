class Solution {
public:

    bool isSafe(int row,int col,vector<string>&temp,int n){
       for(int i=0;i<row;i++){
        if(temp[i][col]=='Q') return false;
       }

       int i=row-1,j=col-1;
       while(i>=0 && j>=0){
        if(temp[i][j]=='Q') return false;
        i--;
        j--;
       }
       i=row-1,j=col+1;
        while(i>=0 && j<n){
        if(temp[i][j]=='Q') return false;
        i--;
        j++;
       }

       return true;
    }
    void func(int n,vector<vector<string>>&ans,vector<string>&temp,int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,temp,n)){
                temp[row][col]='Q';
                func(n,ans,temp,row+1);
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==2 || n==3){
            return {};
        }
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        func(n,ans,temp,0);
        
        return ans;
    }
};