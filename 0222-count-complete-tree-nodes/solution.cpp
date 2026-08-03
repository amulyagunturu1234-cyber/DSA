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
    int findLeftHeight(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->left;
        }
        return ht;
    }
    int findRightHeight(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->right;
        }
        return ht;
    }
    public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh) return(1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
