#define mod 1000000007
class Solution {
public:
   
    long long powe(long long x,long long n){
        if(n==0){
            return 1;
        }
        long long ans=1;
        x=x%mod;
        while(n>0){
            if(n&1){
                ans=(ans*x)%mod;
            }
            x=(x*x)%mod;
            n=n>>1;
        }
        return ans;

    }
    int countGoodNumbers(long long n) {
       long long odd=n/2;
       long long even=n/2+n%2;
       return (powe(5,even)*powe(4,odd))%mod;
    }
};