/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markPar(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&par){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode*>par;
        markPar(root,par);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        int currlevel=0;
        while(!q.empty()){
            int size=q.size();
            if(currlevel==k) break;
            currlevel++;
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(par[curr] && !vis[par[curr]]){
                    q.push(par[curr]);
                    vis[par[curr]]=true;
                }
            }

        }
        vector<int>res;
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};