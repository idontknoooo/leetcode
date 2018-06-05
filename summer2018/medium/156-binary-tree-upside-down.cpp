// 4ms
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        TreeNode* result;
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        while(!(tmp->left == NULL && tmp->right == NULL)){
            stk.push(tmp);
            tmp = tmp->left;
        }
        result = new TreeNode(tmp->val);
        TreeNode* t = result;
        while(!stk.empty()){
            TreeNode* parent = stk.top();
            stk.pop();
            t->left = parent->right;
            t->right = new TreeNode(parent->val);
            t = t->right;
        }
        return result;
    }
};

// 4ms
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return upsideDownBinaryTree(root, NULL, NULL);
    }
    
    TreeNode* upsideDownBinaryTree(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (root == NULL) return right;
        TreeNode* oldLeft = root->left, *oldRight = root->right;
        root->left = left;
        root->right = right;
        return upsideDownBinaryTree(oldLeft, oldRight, root);
    }
};
