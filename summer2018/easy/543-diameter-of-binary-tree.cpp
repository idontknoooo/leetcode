// My solution 
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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        else
            return max(max(height(root->left) + height(root->right), diameterOfBinaryTree(root->left)), diameterOfBinaryTree(root->right));
    }
};


// Faster solution
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
    int maxDepth = 0;
    
    int getMaxDepth(TreeNode* root){
        if (!root) return 0;
        
        int leftDepth = getMaxDepth(root->left);
        int rightDepth = getMaxDepth(root->right);
        
        maxDepth = (leftDepth + rightDepth > maxDepth ) ? leftDepth + rightDepth : maxDepth;
        
        return max(leftDepth +1, rightDepth+1);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getMaxDepth(root);
        return maxDepth;
    }
};
