class Solution {
public:
    vector<string>rowStates;
    int M=1e9+7;
    vector<vector<int>>t;
    void generateRowStates(string curr,char prevChar,int l,int m){
        if(l==m){
            rowStates.push_back(curr);
            return;
        }

        for(char ch:{'R','Y','G'}){
            if(ch==prevChar) continue;

            generateRowStates(curr+ch,ch,l+1,m);
        }
    }

    int solve(int remRows,int prevIdx,int m){
        if(remRows==0) return 1;

        if(t[remRows][prevIdx]!=-1){
            return t[remRows][prevIdx];
        }
        int ways=0;
        string prevState=rowStates[prevIdx];
        for(int i=0;i<rowStates.size();i++){
            string currState=rowStates[i];
            bool valid=true;
            for(int j=0;j<m;j++){
                if(prevState[j]==currState[j]){
                    valid=false;
                    break;
                }
            }

            if(valid){
                ways=(ways+solve(remRows-1,i,m))%M;
            }
        }

        return t[remRows][prevIdx]=ways;
    }
    int numOfWays(int n) {
        generateRowStates("",'#',0,3);
        int totalStates=rowStates.size();
        t=vector<vector<int>>(n+1,vector<int>(totalStates+1,-1));
        int res=0;
        for(int i=0;i<rowStates.size();i++){
            res=(res+solve(n-1,i,3))%M;
        }

        return res;
    }
};