class Solution {
public:
    int reverse(int x) {
        int num=0;
        int n=x;
        
        while(n!=0){
            if(num>INT_MAX/10 || num<INT_MIN/10) return 0; 
            num*=10;
            num+=n%10;
            n/=10;
        }

        
        return num;
    }
};