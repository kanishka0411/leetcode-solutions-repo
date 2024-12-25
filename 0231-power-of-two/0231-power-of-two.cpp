class Solution {
public:
    bool isPowerOfTwo(int n) {
        //powers of two are:      1-0001,  2-0010, 4-0100, 8-1000
        //.              (n-1)--->0-0000,  1-0001, 3-0011, 7-0111
        //               n&(n-1)->0000. ,    0000,  0000,  0000
        return n>0 && (n & (n-1))==0;  
    }
};