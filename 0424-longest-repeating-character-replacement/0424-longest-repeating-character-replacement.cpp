class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=0;
        int n=s.size();
        unordered_map<char,int>mpp;
        int l=0;
        int r=0;
        int maxFreq=0;
        while(r<n){
            mpp[s[r]]++;
            maxFreq=max(maxFreq,mpp[s[r]]);
            int len=r-l+1;
            if(len-maxFreq>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(len-maxFreq<=k){
                maxLen=max(maxLen,len);
            }
            r++;

        }
       return maxLen;
    }

};




// for(int i=0;i<n;i++){
//             unordered_map<int,int>mpp;
//              int maxfreq=0;
//             for(int j=i;j<n;j++){
//                 mpp[s[j]]++;
//                 maxfreq=max(maxfreq,mpp[s[j]]);
//                 int len=j-i+1;
//                 if(len-maxfreq<=k){
//                     maxLen=max(maxLen,len);
//                 }

            // }