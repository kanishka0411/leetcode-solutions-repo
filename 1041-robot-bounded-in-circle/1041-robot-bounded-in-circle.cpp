class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> r={-1,0,1,0};
        vector<int>c={0,1,0,-1};
        int n=instructions.size();
        int x=0;
        int y=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(instructions[i]=='G'){
                x+=r[k];
                y+=c[k];
            }else if(instructions[i]=='L'){
                k=(k-1);
                if(k<0){
                    k=k+4;
                }
            }else{
                k=(k+1)%4;
            }
        }
        if(x==0 && y==0 || k!=0) return true;
        return false;
    }
};