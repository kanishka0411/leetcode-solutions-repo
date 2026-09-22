class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int>total(1001,0);
        for(int i=0;i<n;i++){
            int num=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            total[from]+=num;
            total[to]-=num;
        }
        int inCar=0;
        for(int km=0;km<=1000;km++){
            inCar+=total[km];
            if(inCar>capacity) return false;
        }
        return true;
    }
};