class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int sIdx=-1;
        int minlen=INT_MAX;
        vector<int>hash(256,0);
        for(char c:t){
            hash[c]++;
        }
        int l=0;
        int r=0;
        int cnt=0;
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                  minlen=r-l+1;
                  sIdx=l;
                }
               hash[s[l]]++;
               if(hash[s[l]]>0){
                   cnt--;
                }
               l++;
            }
            r++;
        }
        return sIdx==-1.?"":s.substr(sIdx,minlen);
    }
};