class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
            n=-n;
        }
        if(n==0) return 1;
        if(n%2==1){
            return x*myPow(x*x,(n-1)/2);
        }else{
            return myPow(x*x,n/2);
        }
    }
};