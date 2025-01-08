class Solution {
public:
bool isPrefixAndSuffix(string str1,string str2){
        int len1=str1.size();
        int len2=str2.size();
        if(len1>len2) return false;
        if (str2.compare(0,len1,str1)) return false;
        if (str2.compare(len2-len1,len1,str1)) return false;

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        if(n<2) return 0;
        int i=0,j=1; 
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};