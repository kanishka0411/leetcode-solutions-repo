class Solution {
public:
    double myPow(double x, int n) {
        long long temp=n;
        if(temp<0){
            x=1/x;
            temp=-temp;
        }
        if(temp==0) return 1;
        if(temp%2==1){
            return x*myPow(x*x,(temp-1)/2);
        }else{
            return myPow(x*x,temp/2);
        }
    }
};