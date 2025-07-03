class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
    //------------------------------Brute-----------------------------------
    //    int n=shifts.size();
    //    string ans=s;
    //    for(int i=0;i<n;i++){
    //       for(int j=0;j<=i;j++){
    //        ans[j]=(ans[j]-'a'+shifts[i])%26+'a';     
    //       }
    //     }
        
    //     return ans;
    
    //-----------------------------------Optimal--------------------------------
    int n=s.size();
    vector<long long>suffix(n);
    suffix[n-1]=shifts[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=(suffix[i+1]+shifts[i])%26;
    }
    
    for(int i=0;i<n;i++){
        s[i]=(s[i]-'a'+suffix[i])%26+'a';
    }
    
    return s;
    }
};

/*
int n=shifts.size();
string ans=s;
for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        ans[j]+=shifts[i];
    }
}
return ans;
*/