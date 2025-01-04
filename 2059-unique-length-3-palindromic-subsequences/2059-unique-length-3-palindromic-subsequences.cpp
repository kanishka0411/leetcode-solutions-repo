class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int count=0;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]].push_back(i);
        }
        for(auto &pair:mpp){
            char c =pair.first;
            vector<int>&pos=pair.second;
            if(pos.size()>=2){
                int mini=pos[0];
                int maxi=pos.back();
                unordered_set<char>uni;
                for(int i=mini+1;i<maxi;i++){
                    uni.insert(s[i]);
                }
                if(pos.size()>=3){
                uni.insert(c);
                }
                  count+=uni.size();
            }

            
            
           
        }

        return count;

    }
};