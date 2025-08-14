class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>s;
        for(int i=0;i<n;i++){
            s.push_back({nums[i],i});
        }
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++){
            if(i>0 && s[i].first==s[i-1].first){
                ans[s[i].second]=ans[s[i-1].second];
            }else{
                ans[s[i].second]=i;
            }
        }

        return ans;
    }
};