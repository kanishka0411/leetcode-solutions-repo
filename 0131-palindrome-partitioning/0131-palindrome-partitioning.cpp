class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void func(int ind,string s,vector<vector<string>>&ans,vector<string>&st){
        if(ind==s.size()){
            ans.push_back(st);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                st.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,ans,st);
                st.pop_back();           
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>st;
        func(0,s,ans,st);
        return ans;
    }
};