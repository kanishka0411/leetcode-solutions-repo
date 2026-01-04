class Solution {
public:
    int M=1e9+7;
    vector<string>colStates;
    vector<vector<int>>t;
    void generateColStates(string curr,char prevChar,int l,int m){
        if(l==m){
            colStates.push_back(curr);
            return;
        }

        for(char ch:{'R','G','B'}){
            if(ch==prevChar) continue;

            generateColStates(curr+ch,ch,l+1,m);
        }
    }

    int solve(int remCols,int prevIdx,int m){
        if(remCols==0) return 1;
        if(t[remCols][prevIdx]!=-1){
            return t[remCols][prevIdx];
        }
        int ways=0;
        string prevState=colStates[prevIdx];

        for(int i=0;i<colStates.size();i++){
            if(i==prevIdx) continue;
            string currState=colStates[i];
            bool valid=true;
            for(int j=0;j<m;j++){
                if(prevState[j]==currState[j]){
                    valid=false;
                    break;
                }
            }

            if(valid){
                ways=(ways+solve(remCols-1,i,m))%M;
            }
        }
        return t[remCols][prevIdx]=ways;


    }


    int colorTheGrid(int m, int n) {
        generateColStates("",'#',0,m);
        int totalStates=colStates.size();
        t=vector<vector<int>>(n+1,vector<int>(totalStates+1,-1));
        int res=0;
        for(int i=0;i<colStates.size();i++){
            res=(res+solve(n-1,i, m))%M;
        }

        return res;
    }
};