class Solution {
public:
    int nextGreaterElement(int n) {
       string s=to_string(n);
       int c=s.size();
       int i=0;
       for(i=c-2;i>=0;i--){
        if(s[i]<s[i+1]) break;
       }
       if(i<0) return -1;
       int j=0;
       for(j=c-1;j>i;j--){
        if(s[j]>s[i]) break;
       }

       swap(s[i],s[j]);
       reverse(s.begin()+i+1,s.end());
       long long num=stoll(s);
       return (num>INT_MAX)?-1:(int)num;
    }
};