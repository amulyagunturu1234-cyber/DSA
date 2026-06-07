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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        // Create all nodes and set parent-child relationships
        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal  = desc[1];
            int isLeft    = desc[2];
            
            // Create nodes if they don't exist
            if (nodes.find(parentVal) == nodes.end())
                nodes[parentVal] = new TreeNode(parentVal);
            if (nodes.find(childVal) == nodes.end())
                nodes[childVal] = new TreeNode(childVal);
            
            // Assign child to correct position
            if (isLeft)
                nodes[parentVal]->left  = nodes[childVal];
            else
                nodes[parentVal]->right = nodes[childVal];
            
            // Mark as child
            children.insert(childVal);
        }
        
        // Root is the node that never appears as a child
        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            if (children.find(parentVal) == children.end())
                return nodes[parentVal];
        }
        
        return nullptr;
    }
};
