class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.size();
        vector<string>rows(min(numRows,(int)(n)));
        bool down=false;
        int currrow=0;
        for(char c:s){
            rows[currrow]+=c;
            if(currrow==0 || currrow==numRows-1){
               down=!down;
            }

            currrow+=(down?1:-1);
        }
        string res;
        for(string row:rows){
             res+=row;
        }
        return res;
       
        
    }
};