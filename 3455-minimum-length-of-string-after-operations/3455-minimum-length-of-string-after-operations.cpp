class Solution {
public:
    int minimumLength(string s) {
        vector<int> charf(26, 0);
        int totLen = 0;
        for (char curr : s) {
            charf[curr - 'a']++;
        }
        for (int freq : charf) {
            if (freq == 0) continue;
            if (freq % 2 == 0) {
                totLen += 2;
            } else {
                totLen += 1;
            }
        }
        return totLen;
    }
};
        
    
