class Solution {
public:
    bool isval(int r, int c, int nr, int nc)
    {
        return r >= 0 && c >= 0 && r < nr && c < nc;
    }
    class Cell{
        public:
            int height, row, col;

            Cell(int height, int row, int col) : height(height), row(row), col(col){}

            bool operator<(const Cell& other) const {
                return height >= other.height;
            }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {

        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int drow[4] = {0, 0, -1, 1};
        int dcol[4] = {-1, 1, 0, 0};

        int nrow = heightMap.size();
        int ncol = heightMap[0].size();

        vector<vector<bool>> visit(nrow, vector<bool>(ncol, false));

        priority_queue<Cell> boun;

        for (int i = 0; i < nrow; i++) {
            boun.push(Cell(heightMap[i][0], i, 0));
            boun.push(Cell(heightMap[i][ncol - 1], i, ncol - 1));
            visit[i][0] = visit[i][ncol - 1] = true;
        }
        for (int j = 0; j < ncol; j++) {
            boun.push(Cell(heightMap[0][j], 0, j));
            boun.push(Cell(heightMap[nrow - 1][j], nrow - 1, j));
            visit[0][j] = visit[nrow - 1][j] = true;
        }

        int vol = 0;

        while(!boun.empty())
        {
            Cell currentcell = boun.top();
            boun.pop();

            int currentrow = currentcell.row;
            int currentcol = currentcell.col;
            int minh = currentcell.height;

            for(int i=0; i<4; i++)
            {
                int nerow = currentrow + drow[i];
                int necol = currentcol + dcol[i];               

                if(isval(nerow, necol, nrow, ncol) && !visit[nerow][necol])
                {
                    int neheight = heightMap[nerow][necol];

                    if(neheight < minh)
                    {
                        vol += minh - neheight;
                    }
                    boun.push(Cell(max(minh, neheight), nerow, necol));
                    visit[nerow][necol] = true;
                }
            }
        }
        return vol;
    }
};