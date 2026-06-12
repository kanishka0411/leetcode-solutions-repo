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
    void rec(TreeNode *root,string s,vector<string>&ans){
        if(!root) return;
        if(!s.empty()) s+="->";
        s+=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(s);
        }else{
            if(root->left) rec(root->left,s,ans);
            if(root->right) rec(root->right,s,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s;
        rec(root,s,ans);
        return ans;
    }
};