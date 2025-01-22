class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]) {
                    isWater[i][j] = 0;
                    q.push(make_pair(0,make_pair(i,j)));
                }
                else{
                    isWater[i][j] = -1;
                }
            }
        }
        if(n == m && n == 1) return isWater;
        while(!q.empty()){
            auto curr = q.front();
            int i = curr.second.first;
            int j = curr.second.second;
            if(j-1>=0 && isWater[i][j-1]<0){
                isWater[i][j-1] = curr.first + 1;
                q.push(make_pair(isWater[i][j-1],make_pair(i,j-1))); 
            } 
            if(j+1<m && isWater[i][j+1]<0){
                isWater[i][j+1] = curr.first + 1;
                q.push(make_pair(isWater[i][j+1],make_pair(i,j+1))); 
            } 
            if(i-1>=0 && isWater[i-1][j]<0){
                isWater[i-1][j] = curr.first + 1; 
                q.push(make_pair(isWater[i-1][j],make_pair(i-1,j))); 
            } 
            if(i+1<n && isWater[i+1][j]<0) {
                isWater[i+1][j] = curr.first + 1; 
                q.push(make_pair(isWater[i+1][j],make_pair(i+1,j))); 
            }
            q.pop();
        }
        return isWater;
    }
};