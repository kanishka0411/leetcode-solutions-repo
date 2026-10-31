class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxvow=0;
        int vow=0;
        while(r<n){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u') vow++;
            if(r-l+1>k){
                if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u'){
                    vow--;
                }
                l++;
            }
            if(r-l+1==k){
                maxvow=max(maxvow,vow);
            }
            r++;
        }
        return maxvow;
    }
};