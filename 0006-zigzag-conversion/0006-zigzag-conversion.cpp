class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows==1) return s;
       int n=s.size();
       vector<string>rows(min(n,numRows));
       bool down=false;
       int currrow=0;
       for(char c:s){
        rows[currrow]+=c;
        if(currrow==numRows-1 || currrow==0){
            down=!down;
        }
        currrow+=(down?1:-1);
       }
       string ans;
       for(string r:rows){
            ans+=r;
       }
       return ans;
    }
};