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
    void inorder(TreeNode* root,vector<int> & inordera){
        if(root==NULL) return;
        inorder(root->left,inordera);
        inordera.push_back(root->val);
        inorder(root->right,inordera);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inordera;
        inorder(root,inordera);
        return inordera[k-1];
    }
};
