// Reverse in-order: right->mid->left
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
    int val = 0;
public:
    void help(TreeNode* root){
        if(root && root->right) help(root->right);
        if(root) {
            root->val += val;
            val = root->val;
        }
        if(root && root->left) help(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* node = root;
        help(root);
        return root;
    }
};
