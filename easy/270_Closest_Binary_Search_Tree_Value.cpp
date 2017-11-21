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
//     int closestValue(TreeNode* root, double target) {
//     int a = root->val;
//     auto kid = target < a ? root->left : root->right;
//     if (!kid) return a;
//     int b = closestValue(kid, target);
//     return abs(a - target) < abs(b - target) ? a : b;
// }
    int closestValue(TreeNode* root, double target) {
        stack<TreeNode*> path;
        TreeNode* tmp = root;
        path.push(root);
        while (true) {
            // cout << path.top()->val << ' ' << tmp->val;
            if (abs(path.top()->val - target) < abs(tmp->val - target)) {
                tmp = path.top();
            }
            // cout << ' ' << tmp->val << endl;
            if (target == path.top()->val) {
                return target;
            } else if (target > path.top()->val) {
                if (path.top()->right) {
                    path.push(path.top()->right);
                } else {
                    break;
                }
            } else {
                if (path.top()->left) {
                    path.push(path.top()->left);
                } else {
                    break;
                }
            }
        }
        
        return tmp->val;
    }
};