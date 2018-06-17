// 10ms inorder traverse
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* pLast = NULL;
        stack<TreeNode*> stk;
        while(root || stk.size()) {
            if(root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                // inorder: pLast must less than root
                // pLast is left when root is parent
                // pLast is parent when root is right
                if(!pLast) pLast = root;
                else if(pLast->val>=root->val) return false;
                pLast = root;
                root  = root->right;
            }
        }
        return true;
    }
};

// my slow 15ms solution
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
    int treeMin(TreeNode* root) {
        if(root) return min(min(root->val, treeMin(root->left)), treeMin(root->right));
        else return INT_MAX;
    }
    int treeMax(TreeNode* root) {
        if(root) return max(max(root->val, treeMax(root->left)), treeMax(root->right));
        else return INT_MIN;
    }
    bool isValidBST(TreeNode* root) {
        if(root) {
            if(root->left && root->right) {
                return root->val > treeMax(root->left) && root->val < treeMin(root->right) && isValidBST(root->left) && isValidBST(root->right);
            } else if(root->left) {
                return root->val > treeMax(root->left) && isValidBST(root->left);
            } else if(root->right) {
                return root->val < treeMin(root->right) && isValidBST(root->right);
            } else return true;
        } else return true;
    }
};

