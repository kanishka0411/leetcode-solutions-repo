class Solution {
public:
    void generate(int n,vector<string>&ans,string s,int open,int close){
        if(open==close && (open+close)==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            generate(n,ans,s+'(',open+1,close);
        }
        if(open>close){
            generate(n,ans,s+')',open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        generate(n,ans,s,0,0);
        return ans;
    }
};