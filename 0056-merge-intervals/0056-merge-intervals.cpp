class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        vector<int>temp=intervals[0];
        for(int i=1;i<n;i++){
            int st1=temp[0];
            int end1=temp[1];
            int st2=intervals[i][0];
            int end2=intervals[i][1];

            if(st2<=end1){
                temp[1]=max(end1,end2);
            }else{
                ans.push_back(temp);
                temp=intervals[i];
            }
           

        }
        ans.push_back(temp);
        
        return ans;
    }
};