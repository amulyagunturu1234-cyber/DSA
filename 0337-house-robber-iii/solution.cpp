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
            map<TreeNode*,int>dp;
    int f(TreeNode* node){
        if(node==nullptr)return 0;
        if(dp.count(node))return dp[node];
        int rob=node->val;
        if(node->left){
            rob+=f(node->left->left)+f(node->left->right);
        }
        if(node->right){
            rob+=f(node->right->left)+f(node->right->right);
        }
        int skip=f(node->left)+f(node->right);
        return dp[node]=max(rob,skip);
    }
public:
    int rob(TreeNode* root) {
        return f(root);
    }
};
