class Solution {
public:
    int possibleStringCount(string word) {
        //ye pnc ka lg rha hai 
        //so jo 2 times hai voh 2 time ya 1 time aa skta hai , yani jo 
        // n times appear horha hai that can come n times , 1 actual given 
        // then  so it will be org+(count of different nums-1)
        //ie 1+1+3=5
        int n=word.size(); 
int count=1;
for(int i=n-2;i>=0;i--){
    if(word[i]==word[i+1]){
        count++;
    }
}
return count;
        // so their order also matters , we cant get answer by size only 
        // like eer is different answer and ere is different 
        //eer will give er eer so answer=2 
        //but ere only gives one ->ere
        //because alice eksaath dabaye hue ke permutation legi
    }
};

/*

*/