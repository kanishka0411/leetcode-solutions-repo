class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
       int xoro = 0;
        for (int n:derived) {
            xoro^=n;  
        }
        return xoro==0; 

    }
};