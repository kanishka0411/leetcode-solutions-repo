class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        int count=0,op=0;
        for(int i=0;i<n;i++){
            ans[i]+=op;
            count+=(boxes[i]=='1');
            op+=count;
        }

        count=0,op=0;
        for(int i=n-1;i>=0;i--){
            ans[i]+=op;
            count+=(boxes[i]=='1');
            op+=count;
        }
        
        return ans;
    }
};