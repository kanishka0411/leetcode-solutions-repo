class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>merged;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }

        while(i<n) merged.push_back(nums1[i++]);
        while(j<m) merged.push_back(nums2[j++]);
        int s=n+m;
        if(s%2==1){
            return (double)merged[s/2];
        }

        return ((double)merged[s/2]+(double)merged[(s/2)-1])/2.0;
    }
};