class Solution {
public:
    char kthCharacter(int k) {
     
        string s="a";
        while(s.size()<=k){
            string temp=s;
            for(int i=0;i<temp.size();i++){
             if(temp[i]=='z') s+='a';
             s+=temp[i]+1;
           }
        }
        return s[k-1];
    };
};

/*
string s="a";
while(s.size()<=k){
    for(int i=0;i<s.size();i++){
        if(s[i]=='z') s+='a';
        s+=s[i]+1;
    }
}
return s[k];




  string word="a";//z zyega toh a bnega rest +1 
        while(word.size()<=k){///ese kro
            string gen="";
            for(int i=0;i<word.size();i++){
                if(word[i]=='z') gen[i]='a';
                else gen[i]=word[i]+1;
            }
            word+=gen;
        }
        return word[k]; 
*/