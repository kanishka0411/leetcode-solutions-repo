class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans(m);
        for(int ball=0;ball<m;ball++){
            int col=ball;
            for(int row=0;row<n;row++){
                int next=col+grid[row][col];
                if(next<0 || next>=m){
                    col=-1;
                    break;
                }
                if(grid[row][next]!=grid[row][col]){
                    col=-1;
                    break;
                }
                col=next;
            }
            ans[ball]=col;
        }
        return ans;
    }
};