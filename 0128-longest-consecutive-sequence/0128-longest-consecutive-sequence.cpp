class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int it:st){
            if(st.find(it-1)==st.end()){
                int num=it+1;
                int currlen=1;
                while(st.find(num)!=st.end()){
                    currlen++;
                    num++;
                }
                maxlen=max(maxlen,currlen);

            }
            
        }

        return maxlen;
    }
};