class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        vector<int>y(2051);

        for(int i=0;i<n;i++){
            int birth=logs[i][0];
            int death=logs[i][1];
            y[birth]+=1;
            y[death]-=1;
        }

        int alive=0;
        int bestYear=1950;
        int best=0;
        for(int i=1950;i<=2050;i++){
            alive+=y[i];
            if(alive>best){
                bestYear=i;
                best=alive;
            }
        }
        return bestYear;
    }
};