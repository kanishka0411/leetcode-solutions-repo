class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int count=0;
        int n=s1.size();
        vector<int>diff;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size()==2){
            int i=diff[0];
            int j=diff[1];
            if(s1[i]==s2[j] && s2[i]==s1[j]){
                return true;
            }
        }

        return false;
        
    }
};