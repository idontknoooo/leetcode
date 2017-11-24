/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        // Check leaf situation
        else if(!(root->left && root->right)) return 1 + max(minDepth(root->left), minDepth(root->right));
        // Shortest path between left & right
        else return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
