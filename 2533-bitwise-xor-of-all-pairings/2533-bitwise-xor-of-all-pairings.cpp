class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int xor1=0;
        int xor2=0;
        for(int i=0;i<m;i++){
            xor1^=nums1[i];
        }

        for(int i=0;i<n;i++){
            xor2^=nums2[i];
        }

        if(m%2==0 && n%2==0){
            return 0;
        }else if(m%2!=0 && n%2==0){
            return xor2;
        }else if(m%2==0 && n%2!=0){
            return xor1;
        }



        return xor1^xor2;
    }
};