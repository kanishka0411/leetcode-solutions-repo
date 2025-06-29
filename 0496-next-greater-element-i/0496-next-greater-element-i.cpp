class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //-------------------------------Brute----------------------------------
        // int n=nums1.size();
        // int m=nums2.size();
        //  vector<int>ans(n,-1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(nums1[i]==nums2[j]){
        //             for(int k=j+1;k<m;k++){
        //                 if(nums2[k]>nums1[i]){
        //                     ans[i]=nums2[k];
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }

        ///-----------------------------Optimal---------------------------------
        stack<int>st;
      
        unordered_map<int,int>mpp;
        int n=nums1.size();
        vector<int>ans(n);
        int m=nums2.size();
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]) st.pop();

            if(st.empty()) mpp[nums2[i]]=-1;
            else mpp[nums2[i]]=st.top();

            st.push(nums2[i]);
        }

        for(int i=0;i<n;i++){
            ans[i]=mpp.count(nums1[i])?mpp[nums1[i]]:-1;
        }
        return ans;
    }
};