class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int maxcnt=0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
               int currnum=num;
               int currlen=1;
               while(st.find(currnum+1)!=st.end()){
                currnum++;
                currlen++;
               }
               maxcnt=max(maxcnt,currlen);
            }
        }
        return maxcnt;
         
    }
};