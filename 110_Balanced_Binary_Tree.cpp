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
	// Height for calculation
    int height(TreeNode* root)
    {
        return (!root)? 0 : 1 + max(height(root->left), height(root->right));
    }
	// Orignal function
    bool isBalanced(TreeNode* root) 
    {
		// return true when left & right are balance and left-right <= 1
        return (!root)? true : isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
	}
    
};
