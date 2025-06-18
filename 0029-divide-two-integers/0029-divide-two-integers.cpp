class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(divisor==1) return dividend;

        bool isPositive=true;
        if(dividend>0 && divisor<0) isPositive=false;
        if(dividend<0 && divisor>0) isPositive=false;

        long n=dividend;
        long d=divisor;

        n=abs(n);
        d=abs(d);
        int ans=0;
        while(n>=d){
            int count=0;
            while(n>(d<<(count+1))) count++;

            ans+=(1<<count);
            n-=d*(1<<count);
        }

        if(ans==(1<<31) && isPositive) return INT_MAX;
        if(ans==(1<<31) && !isPositive) return INT_MIN;

        return isPositive?ans:-1*ans;
    }
};