class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.size();
        string ans;
        vector<string>rows(min(n,numRows));
        int currow=0;
        bool down=false;
        for(char c:s){
            rows[currow]+=c;
            if(currow==numRows-1 || currow==0){
                down=!down;
            }
            currow+=down?1:-1;

        }
        for(auto c:rows){
            ans+=c;
        }
        return ans;

    }
};