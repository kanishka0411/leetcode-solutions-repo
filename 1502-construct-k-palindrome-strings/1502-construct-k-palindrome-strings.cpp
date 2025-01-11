class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k){
            return true;
        }
        if(n<k){
            return false;
        }
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }

        int count=0;
        for(auto it:mpp){
            if(it.second%2!=0){
                count++;
            }
           
        }
        return count<=k;
            
    }
};