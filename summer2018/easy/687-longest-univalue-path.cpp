// 83ms
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
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};



// 63ms, post-order
class Solution {
public:
    int mmax;
    // Height for same node value
    int height(TreeNode* root) {     
        if (root==NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        int left = 0;
        if (root->left!=NULL && root->left->val == root->val) {
            left = leftHeight + 1;
        }
        int right = 0;
        if (root->right!=NULL && root->right->val == root->val) {
            right = rightHeight + 1;
        }
        mmax = max(mmax, left + right);
        return max(left, right);
        
    }
    int longestUnivaluePath(TreeNode* root) {        
        mmax = 0;
        height(root);
        return mmax;
    }
};
