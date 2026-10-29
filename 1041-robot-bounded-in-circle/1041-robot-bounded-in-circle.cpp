class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n=instructions.size();
        int h[4]={0,1,0,-1};
        int v[4]={1,0,-1,0};
        int x=0;
        int y=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(instructions[i]=='G'){
                x+=h[k];
                y+=v[k];
            }else if(instructions[i]=='R'){
                k=(k+1)%4;
            }else{
                k=k-1;
                if(k<0){
                    k=k+4;
                }
            }
        }
        return (x==0 && y==0) || k!=0;
    }
};