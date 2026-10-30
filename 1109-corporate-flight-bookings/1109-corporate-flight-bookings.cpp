class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int k=bookings.size();
        vector<int>arr(n+1);
        for(int i=0;i<k;i++){
            int first=bookings[i][0];
            int last=bookings[i][1];
            int seats=bookings[i][2];

            arr[first-1]+=seats;
            arr[last]-=seats;
        }

        vector<int>ans(n);
        int running=0;
        for(int i=0;i<n;i++){
            running+=arr[i];
            ans[i]+=running;
        }
        return ans;
    }
};