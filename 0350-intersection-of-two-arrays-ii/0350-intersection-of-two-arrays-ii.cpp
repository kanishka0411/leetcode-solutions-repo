class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int>freq;

        for(int num:nums1){
            freq[num]++;
        }

        for(int num:nums2){
            if(freq[num]>0){
                res.push_back(num);
                freq[num]--;
            }
        }
        return res;
    }
};