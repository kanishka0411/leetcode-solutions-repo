class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<int>isPrime(n+1,1);
        for(long long  i=2;i<n;i++){
            if (isPrime[i]){
                cnt++;
                for(long long j=i*i;j<n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
        return cnt;
    }
};