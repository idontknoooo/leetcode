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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
    }
};
// Non-Recursive Way
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        deque<TreeNode*> keeper;
        keeper.push_back(root->left);
        keeper.push_back(root->right);
        
        while (keeper.size() > 1) {
            TreeNode* l = keeper.front();
            TreeNode* r = keeper.back();
            keeper.pop_front();
            keeper.pop_back();
            if (l == NULL && r == NULL) continue;
            if (l == NULL || r == NULL || l->val != r->val) return false;
            keeper.push_front(l->right);
            keeper.push_front(l->left);
            keeper.push_back(r->left);
            keeper.push_back(r->right);
        }
        
        return keeper.empty();
    }
};