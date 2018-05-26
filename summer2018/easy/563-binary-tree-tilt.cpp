// My solution 25ms
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
    int val(TreeNode* root){
        if(!root) return 0;
        else {
            int l = 0, r = 0;
            if(root->left) l = val(root->left);
            if(root->right) r = val(root->right);
            int value = l + r + root->val;
            return value;
        }
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        if(!root) return 0;
        if(root->left && root->right){
            sum = abs(val(root->left) - val(root->right));
        } else if(root->left) {
            sum = abs(val(root->left));
        } else if(root->right) {
            sum = abs(val(root->right));
        } 
        return sum + findTilt(root->left) + findTilt(root->right);
    }
};



// 15 ms
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
    int postOrder(TreeNode* root, int& ret) {
        if (!root) return 0;
        int leftSum = postOrder(root->left, ret);
        int rightSum = postOrder(root->right, ret);
        ret += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
    
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int ret = 0;
        postOrder(root, ret);
        return ret;
    }
};
