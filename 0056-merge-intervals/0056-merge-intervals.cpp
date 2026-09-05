class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            if(ans.empty()){
                ans.push_back({st,end});
            }else{
                if(st<=ans.back()[1]){
                    ans.back()[1]=max(ans.back()[1],end);
                }else{
                    ans.push_back({st,end});
                }
            }
        }
        return ans;
    }
};