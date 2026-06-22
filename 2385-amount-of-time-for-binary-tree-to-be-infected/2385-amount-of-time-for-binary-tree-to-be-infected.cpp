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
    void markpar(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&par,TreeNode* &target,int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->val==start) target=node;
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode *target=nullptr;
        unordered_map<TreeNode*,TreeNode*>par;
        markpar(root,par,target,start);
        int time=0;
        unordered_map<TreeNode*,bool>vis;
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
                    burned=true;
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    burned=true;
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(par[curr] &&!vis[par[curr]]){
                    burned=true;
                    q.push(par[curr]);
                    vis[par[curr]]=true;
                }
            }
            if(burned) time++;
        }
        return time;
    }
};