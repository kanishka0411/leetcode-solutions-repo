class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        int m=s.size();
        vector<int>change(m+1);
        for(int i=0;i<n;i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int amount=(shifts[i][2]==0)?-1:1;
            change[start]+=amount;
            change[end+1]-=amount;
        }
        int shift=0;
        for(int i=0;i<m;i++){
            shift+=change[i];
            int x=s[i]-'a'+shift;
            s[i]='a'+((x%26)+26)%26;
        }
        return s;
        
    }

};