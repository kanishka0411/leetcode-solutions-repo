class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0];
        string second=strs[n-1];
        string res="";
        for(int i=0;i<strs[0].size();i++){
            if(first[i]==second[i]) res+=first[i];
            else break;
        }
        return res;
    }
};