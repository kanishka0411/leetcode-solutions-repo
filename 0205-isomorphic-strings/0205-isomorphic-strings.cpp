class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int n=s.size();
       int s1[256]={0},t1[256]={0};
       for(int i=0;i<n;i++){
        if((s1[s[i]]!=0 || t1[t[i]]!=0) && (s1[s[i]]!=t[i]+1 || t1[t[i]]!=s[i]+1)){
            return false;
        }
        s1[s[i]]=t[i]+1;
        t1[t[i]]=s[i]+1;
       }

       return true;
    }
};