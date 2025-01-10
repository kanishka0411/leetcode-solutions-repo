class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
          vector<string>ans;
        vector<int>maxfreq(26,0);//here we store char with how many times we have
        for(string&word :words2){
            vector<int>freq(26,0);
            for(char c:word){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                maxfreq[i]=max(freq[i],maxfreq[i]);
            }
        }

        for(string& word:words1){
            vector<int>freq(26,0);
            for(char c:word){
                freq[c-'a']++;
            }
            bool present=true;
            for(int i=0;i<26;i++){
                if(freq[i]<maxfreq[i]){
                    present=false;
                    break;
                }
            }
            if(present) ans.push_back(word);
        }

        return ans;

    }
};