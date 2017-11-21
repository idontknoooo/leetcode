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
    int sumOfLeftLeaves(TreeNode* root) {
        // if (!root) return 0;
        // if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        // return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        stack<TreeNode *> stk;
        if (root == nullptr) return 0;
        int sum = 0;
        stk.push(root);
        
        while (!stk.empty()) {
            auto cur = stk.top(); stk.pop();
            if (cur->left) {
                if (cur->left->left == nullptr && cur->left->right == nullptr)
                    sum += cur->left->val;
                else
                    stk.push(cur->left);
            }
            if (cur->right) {
                if (cur->right != nullptr || cur->left != nullptr)
                    stk.push(cur->right);
            }
        }
        return sum;
    }
};