// My solution 4ms
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
    int minDiff = INT_MAX;
public:
    int largest(TreeNode* root, int val) {
        if(root && root->right) {
            return largest(root->right, root->val);
        } else if(root) return root->val;
        else return val;
    }
    int smallest(TreeNode* root, int val) {
        if(root && root->left) {
            return smallest(root->left, root->val);
        } else if(root) return root->val;
        else return val;
    }
    int minDiffInBST(TreeNode* root) {
        if(root) {
            int d1 = abs(root->val - smallest(root->right, root->val));
            if(d1) minDiff = min(minDiff, d1);
            int d2 = abs(root->val - largest(root->left, root->val));
            if(d2) minDiff = min(minDiff, d2);
            return min(min(minDiff, minDiffInBST(root->left)), minDiffInBST(root->right));
        } else return minDiff;
    }
};

// 4ms: level by level inorder
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
    int minDiffInBST(TreeNode* root) {
        int val = -1;
        int diff = INT_MAX;
        traverse(root, val, diff);
        return diff;
    }
    
    void traverse(TreeNode* root, int& val, int& diff) {
        if(root -> left) {
            traverse(root -> left, val, diff);
        }
        if(val >= 0) {
            diff = min(diff, root -> val - val);
        }
        val = root -> val;
        if(root -> right) {
            traverse(root -> right, val, diff);
        }
    }
};
