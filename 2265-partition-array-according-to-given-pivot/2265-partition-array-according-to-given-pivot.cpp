class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        //-------------------------------------Brute--------------------------------------------//
        // int n=nums.size();
        // vector<int>one;
        // vector<int>two;
        // vector<int>three;
        // vector<int>ans;

        // for(int i=0;i<n;i++){
        //     if(nums[i]<pivot){
        //         one.push_back(nums[i]);
        //     }
        //     if(nums[i]==pivot){
        //         two.push_back(nums[i]);
        //     }
        //     if(nums[i]>pivot){
        //         three.push_back(nums[i]);
        //     }
        // }
        // ans.insert(ans.end(),one.begin(),one.end());
        // ans.insert(ans.end(),two.begin(),two.end());
        // ans.insert(ans.end(),three.begin(),three.end());

        //--------------------------------------Optimized iteration-------------------------------//
        // int n=nums.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<pivot){
        //         ans.push_back(nums[i]);
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(nums[i]==pivot){
        //         ans.push_back(nums[i]);
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(nums[i]>pivot){
        //         ans.push_back(nums[i]);
        //     }
        // }

        //-------------------------------------------BEST------------------------------------------
        int n=nums.size();
        vector<int>ans(n,0);
        int i=0;
        int j=n-1;
        int ansi=0;
        int ansj=n-1;
        while(i<n && j>=0){
            if(nums[i]<pivot){
                ans[ansi]=nums[i];
                ansi++;
            }
            if(nums[j]>pivot){
                ans[ansj]=nums[j];
                ansj--;
            }
            i++;
            j--;
        }

        while(ansi<=ansj){
            ans[ansi]=pivot;
            ansi++;
        }
        return ans;
    }
};