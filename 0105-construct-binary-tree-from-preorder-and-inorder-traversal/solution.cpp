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
    TreeNode* PostIn(vector<int> &inorder,int is,int ie,vector<int> &preorder,int ps,int pe,map<int,int> &mpp){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inRoot=mpp[root->val];
        int numsLeft=inRoot-is;
        root->left=PostIn(inorder,is,inRoot-1,preorder,ps+1,ps+numsLeft,mpp);
        root->right=PostIn(inorder,inRoot+1,ie,preorder,ps+numsLeft+1,pe,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()) return NULL;
        map<int,int>mpp;//for finding root for inorder
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return PostIn(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mpp);
    }
};
