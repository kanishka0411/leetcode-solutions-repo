class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>last(26,0);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        vector<int>ans;
        int marker=0;
        int start=0;
        for(int i=0;i<n;i++){
            marker=max(marker,last[s[i]-'a']);

            if(i==marker){
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};