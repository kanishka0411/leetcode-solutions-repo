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
    const int M=1e9+7;
    long long dfs(TreeNode *root, long long &maxProd,long long &tsum){
        if(root==nullptr) return 0;
        long long lh=dfs(root->left,maxProd,tsum);
        long long rh=dfs(root->right,maxProd,tsum);
        long long sum=lh+rh+root->val;
        maxProd=max(maxProd,sum*(tsum-sum));
        return sum;

    }
    void getSum(TreeNode *root,long long &sum){
        if(root==nullptr) return;
        sum+=root->val;
        getSum(root->left,sum);
        getSum(root->right,sum);
    }
    int maxProduct(TreeNode* root) {
        long long sum=0;
        getSum(root,sum);
        long long maxProd=INT_MIN;
        dfs(root,maxProd,sum);
        return maxProd%M;

    }
};