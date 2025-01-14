class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        vector<int>count(n+1,0);
        int c=0;
        for(int i=0;i<n;i++){
            
            count[A[i]]++;
            if(count[A[i]]==2){
                c++;
            }
            count[B[i]]++;
            if(count[B[i]]==2){
                c++;
            }

            ans[i]=c;

        }
        return ans;
    
    }
};