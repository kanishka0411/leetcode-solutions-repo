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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        queue<TreeNode*>p1;
        queue<TreeNode*>q1;
        p1.push(p);
        q1.push(q);
        while(!p1.empty() && !q1.empty()){
                TreeNode *node=p1.front();
                p1.pop();
                TreeNode *node1=q1.front();
                q1.pop();
                if(!node && !node1) continue;
                if(!node || !node1 || node->val!=node1->val) return false;

                p1.push(node->left);
                p1.push(node->right);
                q1.push(node1->left);
                q1.push(node1->right);
                
        }
        return p1.empty() && q1.empty();

    }
};