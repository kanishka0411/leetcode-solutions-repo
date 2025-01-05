class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.size();
        vector<int> effects(len + 1, 0);

        for (const auto&shift:shifts) {
            int l=shift[0];
            int r=shift[1];
            int effect=shift[2];

            if(effect==1) {
                effects[l]+=1;
                if(r+1<len) effects[r+1]-=1;
            }else if (effect == 0) {
                effects[l] -= 1;
                if (r+1<len)effects[r + 1]+=1;
            }
        }

        int curr = 0;
        for (int i=0;i<len;i++) {
            curr +=effects[i];
            int net=curr%26;
            if (net < 0) net+=26;
            s[i]='a'+(s[i]-'a'+net)%26;
        }

        return s;
    }
};