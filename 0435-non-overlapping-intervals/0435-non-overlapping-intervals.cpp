class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int end=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            int st=intervals[i][0];
            int en=intervals[i][1];
            if(st<end){
                cnt++;
                end=min(end,en);
            }else{
                end=en;
            }
        }
        return cnt;
    }
};