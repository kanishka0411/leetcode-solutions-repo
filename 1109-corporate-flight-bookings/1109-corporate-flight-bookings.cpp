class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>psum(n+1);
        int m=bookings.size();
        for(int i=0;i<m;i++){
            int first=bookings[i][0];
            int last=bookings[i][1];
            int seats=bookings[i][2];

            psum[first-1]+=seats;
            psum[last]-=seats;
            
        }
        int running=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            running+=psum[i];
            ans[i]=running;
        }
        return ans;


    }
};