class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.size();
        int last[3]={-1,-1,-1};
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
            if(last[0]!=-1 && last[1]!=-1 && last[2]!=-1){
                count+=1+min({last[0],last[1],last[2]});
            }
        }
        return count;
    }
};



/*for(int i=0;i<n;i++){
            string str;
            for(int j=i;j<n;j++){
                str+=s[j];
                if(str.find('a')!=string::npos && str.find('b')!=string::npos && str.find('c')!=string::npos){
                    len++;
                }
            }
        }*/