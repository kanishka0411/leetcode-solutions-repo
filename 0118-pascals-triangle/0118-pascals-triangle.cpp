class Solution {
public:

    vector<int>gen(int row){
        long long res=1;
        vector<int>temp;
        temp.push_back(res);
        for(int i=1;i<=row;i++){
            res*=row-i+1;
            res/=i;
            temp.push_back(res);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(gen(i));
        }
        return ans;
        
    }
};