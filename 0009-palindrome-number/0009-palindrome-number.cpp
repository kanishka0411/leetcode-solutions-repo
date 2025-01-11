class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        if(x<0){
            return false;
        }
        int n=0;
        while(x>0){
            if(n>INT_MAX/10){
                return false;
            }
            n*=10;
            n+=x%10;
            x/=10;
        }

        return num==n;

    }
};