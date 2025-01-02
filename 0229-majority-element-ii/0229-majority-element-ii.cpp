class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        int el1=-1;
        int el2=-1;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1=1;
                el1=nums[i];
            }else if(cnt2==0 && el1!=nums[i]){
                cnt2=1;
                el2=nums[i];
            }else if(el1==nums[i]){
                cnt1++;
            }else if(el2==nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        int counter1=0;
        int counter2=0;

        for(int i=0;i<n;i++){
            if(el1==nums[i]){
                counter1++;
            }

            if(el2==nums[i]){
                counter2++;
            }
        }

        if(counter1>(n/3)){
            res.push_back(el1);
        }
        if(counter2>(n/3) && el1!=el2){
            res.push_back(el2);
        }

        return res;
        
    }
};