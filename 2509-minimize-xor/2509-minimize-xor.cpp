class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        while(num2){
            cnt+=num2&1;
            num2>>=1;
        }
        int x=0;
        for(int i=31;i>=0;i--){
            //we check set bits 
            if(num1&(1<<i) && cnt>0){
                x|=(1<<i);//set that
                cnt--;
            }
        }
        //still left
        for(int i=0;i<32 && cnt>0;i++){
            if(!(x&(1<<i))){//if bit not set we set that and dec cnt 
                x|=(1<<i);
                cnt--;
            }
        }
        return x;
    }
};