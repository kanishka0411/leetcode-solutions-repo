/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode *root,unordered_map<TreeNode *,TreeNode *>&parent,TreeNode *&target,int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->val==start){
                target=curr;
            }
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }

            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *,TreeNode*>parent;
        TreeNode *target=nullptr;
        markParent(root,parent,target,start);

        unordered_map<TreeNode*,bool>vis;
        int time=0;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            int size=q.size();
            bool burned=false;
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    vis[curr->left]=true;
                    burned=true;
                    q.push(curr->left);
                }

                if(curr->right && !vis[curr->right]){
                    burned=true;
                    vis[curr->right]=true;
                    q.push(curr->right);
                }

                if(parent[curr] && !vis[parent[curr]]){
                    burned=true;
                    vis[parent[curr]]=true;
                    q.push(parent[curr]);
                }

            }
            if(burned) time++;
        }
        return time;
    }
};