class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>st;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && words[j].find(words[i])!=string::npos){
                    st.insert(words[i]);
                }
            }
        }   
        vector<string>ans(st.begin(),st.end());
        return ans;    
    }
};