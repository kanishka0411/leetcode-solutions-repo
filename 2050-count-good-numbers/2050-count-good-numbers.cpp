class Solution {
public:
    #define mod 1000000007
    int powe(long long x,long long n){
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
        if(n==1){
            return 5;
        }
       if(n%2==0){
        return (1LL*powe(5,n/2)*powe(4,n/2))%mod;
       }else{
        return (1LL*powe(5,((n+1)/2))*powe(4,n/2))%mod;
       }
    }
};