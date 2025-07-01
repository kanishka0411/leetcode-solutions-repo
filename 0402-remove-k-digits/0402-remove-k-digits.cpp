class Solution {
public:
    string removeKdigits(string num, int k) {
        //we will always remove digits from start as that decrease fast
        //just keep care of leading zeroes , if we face zero after removing 
        //zeroes we also remove those zeroes till we get any other number 
        //like in example 2 10200 only 1 removed but still we remove 0
        //and if stack becomes empty we return 0 then and there no matter 
        //what k is
        //compile error kyu
        
        //remove leading zeroes also kani kyuki second glt hai 0200 , pop till
        //point we get 0 , if any other stop popping , even mujhe leading zeroes remve krna nhi aara why don't you try
        //bs pop till we have anynh oither number haan but beech ke zeroes ho jayenge pop, nhi hum ruk jayneg if we get non zero number like 0200 mei 
        // pop 0 then we see 2 , so we exit there so ans 200 tum kro code tumhaee saamen haio
        // i think pointer will be better rather than using stack we can straight away skip k  values or more depending on 0 leading and return after that by using ptr, bolo kani arey nhi stack se hi hoga yr kyunki hume pop krte jaana hia na poointer se nhi hoga kese hoga bolo zaroori nhi hai keshav ki contiguis values skip hogi pointer se yhi hoga bs isme beech se kahin se bhi values pop krni ho skti hai aage se
    //pointers use krne se tha is not possibep, kani pr small krne ke liye 
    //aage se hi krenge yehi hint hai isko stack se hojayega niche comment pdho likha hai hm tum kro fir try
        int n=num.size();
        if(k==n) return "0";
        stack<int>st;
        string s;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k!=0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;//ye last case ke liye 112 mein 2 isliye nhi hua kyunki loop over hp gyi thi but k was still greater than 0 it has to be 0 so we have to do a while loop again in order to remove exactly k digits now try
        }
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        
        while(s.size()>0 && s.back()=='0'){
            s.pop_back();
        }
        reverse(s.begin(),s.end());
        return s.empty()?"0":s;
       
    } 
};