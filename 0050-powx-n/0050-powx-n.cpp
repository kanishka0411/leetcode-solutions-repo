class Solution {
public:
    double myPow(double x, int n) {

        //-----------------------------------Brute----------------------------------
        // int temp=n;
        // if(n<0){
        //     x=1/x;
        //     temp*=-1;
        // }
        // double ans=1;
        // for(int i=1;i<=temp;i++){
        //     ans*=x;
        // }
        // return ans;

        //------------------------------------Optimal---------------------------------
        if(n==0){
            return 1;
        }
       long long temp=n;
        if(temp<0){
            x=1/x;
            temp=-temp;
        }
        if(temp%2==1){
            return x*myPow(x,temp-1);
        }

        return myPow(x*x,temp/2);
    }
};