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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> res;
        vector<int> row;
        TreeNode *last, *pre_last = root, *cur = root;
        queue<TreeNode*> nodes;
        nodes.push(cur);
        while (!nodes.empty()) {
            cur = nodes.front();
            row.push_back(cur->val);
            if (cur->left) {
                nodes.push(cur->left);
                last = cur->left;
            }
            if (cur->right) {
                nodes.push(cur->right);
                last = cur->right;
            }
            if (cur == pre_last) {
                res.push_back(row);
                row.clear();
                pre_last = last;
            }
            nodes.pop();
        }
        return res;
    }
};
