class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int studentSize=g.size();
        int cookieSize=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        while(l<studentSize && r<cookieSize){
            if(s[r]>=g[l]){
              l++;
            }
            r++;
        }
        return l;
    }
};