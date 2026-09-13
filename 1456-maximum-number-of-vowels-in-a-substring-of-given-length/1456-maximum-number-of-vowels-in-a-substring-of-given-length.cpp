class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxvow=-1;
        int cnt=0;
        while(r<n){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u') cnt++;
            if(r-l+1>k){
                if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u') cnt--;
                l++;
            }
            if(r-l+1==k){
                maxvow=max(maxvow,cnt);
            }
            r++;
        }
        return maxvow;
    }
};