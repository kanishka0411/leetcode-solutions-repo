class Solution {
public:
    bool isSafe(int row,int col,vector<string>temp,int n){
        for(int i=0;i<row;i++){
            if(temp[i][col]=='Q') return false;
        }

        int i=row;
        int j=col;
        while(i>=0 && j>=0){
            if(temp[i][j]=='Q') return false;
            i--; 
            j--;
        }

        i=row;
        j=col;
        while(i>=0 && j<n){
            if(temp[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void func(int n,vector<vector<string>>&ans,vector<string>&temp,int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
           if(isSafe(i,col,temp,n)){
            temp[i][col]='Q';
            func(n,ans,temp,i+1);
            temp[i][col]='.';
           } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        func(n,ans,temp,0);
        return ans;
    }
};