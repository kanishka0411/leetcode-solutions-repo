class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        string left="";
        for(int i=0;i<n;i++){
            string right=s.substr(i);
            if(right+left==goal) return true;
            left+=s[i];
        }
        return false;
        
    }
};