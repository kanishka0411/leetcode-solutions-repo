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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>arr;
        if(root==nullptr) return arr;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            arr.push_back(root->val);
            if(root->left!=nullptr){
                st.push(root->left);
            }
            if(root->right!=nullptr){
                st.push(root->right);
            }
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};