class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double halfPow=myPow(x,n/2);
        double halfPowSq=halfPow*halfPow;

        if(n%2!=0){
            return (n>0)?x*halfPowSq:halfPowSq/x;
        }

        return halfPowSq;
    }
};