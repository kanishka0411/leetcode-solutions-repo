class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int l=0;
        int r=n-1;
        while(r>=0 && (num[r]-'0')%2==0) r--;
        while(num[l]-'0'==0) l++;
        if(r<0) return "";
        return num.substr(l,r-l+1);
    }
};