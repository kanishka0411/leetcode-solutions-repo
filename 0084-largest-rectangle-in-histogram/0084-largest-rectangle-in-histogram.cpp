class Solution {
public:
    vector<int>findNSE(vector<int>&heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=!st.empty()?st.top():n;
            
            st.push(i);
            
        }
        
        return ans;
    }
    
    vector<int>findPSE(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            
            ans[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=findNSE(heights);
        vector<int>pse=findPSE(heights);
        int n=heights.size();
        int largestArea=0;
        int area;
        
        for(int i=0;i<n;i++){
            area=heights[i]*(nse[i]-pse[i]-1);
            largestArea=max(largestArea,area);
        }
        
        return largestArea;
    }
};