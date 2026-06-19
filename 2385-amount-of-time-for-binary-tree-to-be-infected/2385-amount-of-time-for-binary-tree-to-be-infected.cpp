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
    void markpar(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&mpp,int start,TreeNode *&target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->val==start) target=node;
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        TreeNode *target=nullptr;
        markpar(root,mpp,start,target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int time=0;
        while(!q.empty()){
            bool burned=false;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    burned=true;
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    burned=true;
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(mpp[node] && !vis[mpp[node]]){
                    burned=true;
                    q.push(mpp[node]);
                    vis[mpp[node]]=true;
                }
            }
            if(burned) time++;
        }
        return time;

    }
};