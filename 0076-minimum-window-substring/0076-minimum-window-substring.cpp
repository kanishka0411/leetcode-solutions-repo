class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int sindex=-1;
        int minLen=INT_MAX;
        int n=s.size();
        int l=0;
        int r=0;
        int hash[256]={0};
        for(auto c:t){
            hash[c]++;
        }
        int count=0;
        while(r<n){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minLen){
                    minLen=min(minLen,r-l+1);
                    sindex=l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
                l++;
                
               
            }
             r++;
        }
        return (sindex==-1)?"":s.substr(sindex,minLen);
    }
};






/*for(int i=0;i<n;i++){
            int hash[256]={0};
            for(auto c:t){
                hash[c]++;
            }
            int count=0;
            for(int j=i;j<n;j++){
                if(hash[s[j]]>0) count++;
                hash[s[j]]--;
                if(count==t.size()){
                    if(j-i+1<minLen){
                        minLen=j-i+1;
                        sindex=i;
                        
                    }
                    break;
                }
            }
        }*/