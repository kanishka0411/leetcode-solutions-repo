class Solution {
public:
    int maxrec(vector<int>&arr){
        int area;
        int largestArea=0;
        int nse,pse;
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int ind=st.top();
                st.pop();
                pse=!st.empty()?st.top():-1;
                nse=i;

                area=arr[ind]*(nse-pse-1);
                largestArea=max(largestArea,area);
            }
            st.push(i);
        }

        while(!st.empty()){;
          nse=n;
          int ind=st.top();
          st.pop();
          pse=!st.empty()?st.top():-1;
          area=arr[ind]*(nse-pse-1);
          largestArea=max(largestArea,area);
        }


        return largestArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>psum(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0'){
                    sum=0;
                }

                psum[i][j]=sum;
            }
        }
        int largestArea=0;
        for(int i=0;i<n;i++){
            int area=maxrec(psum[i]);
            largestArea=max(area,largestArea);
        }

        return largestArea;
    }
};