class Solution {
public:
    vector<string> findWords(vector<string>& words) {
int n=words.size();
vector<string>ans;
unordered_set<char>r1;
unordered_set<char>r2;
unordered_set<char>r3;

for(auto c:"qwertyuiop"){
    r1.insert(c);
}
for(auto c:"asdfghjkl"){
    r2.insert(c);
}
for(auto c:"zxcvbnm"){
    r3.insert(c);
}

for(int i=0;i<n;i++){
    int cnt=0;
    int cnt1=0;
    int cnt2=0;
    for(int j=0;j<words[i].size();j++){
        if(r1.find(tolower(words[i][j]))!=r1.end()){
            cnt++;
        }
        //nhi chL rha ye noob
        if(r2.find(tolower(words[i][j]))!=r2.end()){
            cnt1++;
        }
        if(r3.find(tolower(words[i][j]))!=r3.end()){
            cnt2++;
        }
    }
    if(cnt==words[i].size() || cnt1==words[i].size() || cnt2==words[i].size()){
        ans.push_back(words[i]);
    }
}
return ans;
    }
};

/*
int n=words.size();
vector<string>ans;
unordered_set<char>r1;
unordered_set<char>r2;
unordered_set<char>r3;

for(auto c:"qwertyuiop"){
    r1.insert(c);
}
for(auto c:"asdfghjkl"){
    r2.insert(c);
}
for(auto c:"zxcvbnm"){
    r3.insert(c);
}

for(int i=0;i<n;i++){
    int cnt=0;
    int cnt1=0;
    int cnt3=0;
    for(int j=0;j<word[i].size();j++){
        if(r1.find(tolower(words[i][j]))){
            cnt++;
        }
        if(r2.find(tolower(words[i][j]))){
            cnt1++;
        }
        if(r3.find(tolower(words[i][j]))){
            cnt2++;
        }
    }
    if(c1==words[i].size() || c2==words[i].size() || c3==words[i].size()){
        ans.push_back(words[i]);
    }
}
return ans;
*/