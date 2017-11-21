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
    // void invert(TreeNode* root) {
    //     TreeNode* tmp;
    //     if(root)
    //         tmp = root->left;
    //     root->left = root->right;
    //     root->right = tmp;
    // }
    // TreeNode* invertTree(TreeNode* root) {
    //    if(root)
    //    {
    //        invert(root);
    //        invertTree(root->left);
    //        invertTree(root->right);
    //    }
    //    return root;     
    // }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* tmp =invertTree(root->right);
        root->right=invertTree(root->left);
        root->left=tmp;
        return root;
    }
};