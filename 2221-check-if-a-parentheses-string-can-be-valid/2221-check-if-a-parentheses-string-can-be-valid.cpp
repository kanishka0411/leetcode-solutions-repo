class Solution {
public:
    bool canBeValid(string s, string locked) {
          int n=s.size();
        if(n%2!=0) return false;

        int lock_left=0,lock_right=0,unlock=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    lock_left++;
                }
                else lock_right++;
            }
            else unlock++;
        }

        int condn=unlock-(lock_left-lock_right);
        if(condn%2!=0) return false;
        int x=condn/2;
        if(x<0 || x>unlock) return false;

        int min_bal=0,max_bal=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    min_bal++;
                    max_bal++;
                }
                else{
                    min_bal--;
                    max_bal--;
                }
            }
            else{
                min_bal--;
                max_bal++;
            }
            if(max_bal<0) return false;
            if(min_bal<0) min_bal=0;
        }


        return (min_bal==0);
    }
};