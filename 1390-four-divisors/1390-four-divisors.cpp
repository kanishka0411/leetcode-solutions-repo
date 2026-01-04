class Solution {
public:

    int solve(int n){
        int sum=0;
        int cnt=0;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                sum+=i;
                cnt++;
                if(n/i!=i){
                    sum+=n/i;
                    cnt++;
                }
                if(cnt>4) return 0;
            }
            
        }
        return (cnt==4)?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=solve(nums[i]);
        }

        return total;
    }
};