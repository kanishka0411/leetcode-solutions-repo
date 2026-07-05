class Solution {
public:
    void bfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<int>vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};