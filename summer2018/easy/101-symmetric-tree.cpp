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
    bool mirror(TreeNode* a, TreeNode* b){
       if(a && b && a->val==b->val){
           return mirror(a->left, b->right) && mirror(a->right, b->left);
       } else if (!a && !b){
           return true;
       } else {
           return false;
       }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root || !(root->left || root->right)) return true;
        if(!root->left && !root->right) return false;
        return mirror(root->left, root->right);
        // return !root || mirror(root->left, root->right);
    }
};

// Simplified same code
class Solution {
public:
    bool mirror(TreeNode* a, TreeNode* b){
       return (a && b && a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left)) || (!a && !b);
    }
    bool isSymmetric(TreeNode* root) {
        return !root || mirror(root->left, root->right);
    }
};
