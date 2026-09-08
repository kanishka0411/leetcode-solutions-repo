class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxAmount=0;
        int curr=0;
        int i=0;
        int j=n-1;
        while(i<j){
            curr=min(height[i],height[j])*(j-i);
            maxAmount=max(maxAmount,curr);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxAmount;
        
    }
};