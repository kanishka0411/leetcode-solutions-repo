class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
     
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                bool alive=true;
                while(!st.empty()){
                    int ast=st.top();
                    if(abs(asteroids[i])==ast){
                        st.pop();
                        alive=false;
                        break;
                    }else if(ast<0){
                        st.push(asteroids[i]);
                        alive=false;
                        break;
                    }else if(abs(asteroids[i])<ast){
                        alive=false;
                        break;
                    }else{
                        alive=true;
                        st.pop();
                        continue;
                    }
                }
                if(alive){
                    st.push(asteroids[i]);
                }
            }
        }

        while(!st.empty()){
            auto it=st.top();
            st.pop();
            ans.push_back(it);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};