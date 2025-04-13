class Solution {
public:
    void func(int ind,string digits,vector<string>&ans,string s,string combos[]){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }

        int digit=digits[ind]-'0';
        for(int i=0;i<combos[digit].size();i++){
            func(ind+1,digits,ans,s+combos[digit][i],combos);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()) return ans;
        string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        func(0,digits,ans,s,combos);
        return ans;
    }
};