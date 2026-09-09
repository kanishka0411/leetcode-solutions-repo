class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(auto &obs: obstacles){
            st.insert({obs[0],obs[1]});
        }
        int x=0;
        int y=0;
        int dir=0;
        int ans=0;
        int n=commands.size();
        vector<int>r={0,1,0,-1};
        vector<int>c={1,0,-1,0};
        for(int i=0;i<n;i++){
            if(commands[i]==-1){
               dir=(dir+1)%4;
            }else if(commands[i]==-2){
                dir=(dir+3)%4;
            }else{
                for(int step=0;step<commands[i];step++){
                    int nx=x+r[dir];
                    int ny=y+c[dir];
                    if(st.count({nx,ny})) break;
                    x=nx;
                    y=ny;
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};