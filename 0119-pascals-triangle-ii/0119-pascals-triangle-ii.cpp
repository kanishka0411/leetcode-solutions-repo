class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        long long res=1;
        temp.push_back(res);
        for(int i=1;i<=rowIndex;i++){
            res*=rowIndex-i+1;
            res/=i;

            temp.push_back(res);
        }
        return temp;
        
    }
};