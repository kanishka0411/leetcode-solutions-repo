class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0;
        int r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<g.size() && r<s.size()){
            if(s[r]>=g[l]) {
                l++;
            }
            r++;
        }
        return l;

    }
};