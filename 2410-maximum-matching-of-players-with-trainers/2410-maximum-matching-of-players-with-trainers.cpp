class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l=0;
        int r=0;
        while(l<n && r<m){
            if(players[l]<=trainers[r]) l++;
            r++;
        }
        return l;
    }
};