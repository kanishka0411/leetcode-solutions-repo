class Solution {
public:
    string triangleType(vector<int>& nums) {
        int count=0;
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(a+b<=c || b+c<=a || c+a<=b) return "none";
        int n=nums.size();
        if(a==b) count++;
        if(b==c) count++;
        if(a==c) count++;
       
        if(count==3) return "equilateral";
        else if(count==1) return "isosceles";
        else return "scalene";
    }
};