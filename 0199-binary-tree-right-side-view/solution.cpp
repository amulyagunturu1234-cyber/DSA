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
    private:
    void f(TreeNode* node,int level,vector<int>& result){
        if(node==NULL) return;
        if(level==result.size()) result.push_back(node->val);
        f(node->right,level+1,result);
        f(node->left,level+1,result);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL) return result;
        f(root,0,result);
        return result;
    }
};
