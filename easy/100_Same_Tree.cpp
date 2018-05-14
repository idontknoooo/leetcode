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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
// Alternative: Combine if & return
//		if (!p || !q) return (p == q);
//    	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

// Non-recursive
class Solution {
public:
    int m(TreeNode *&h) {
        int v = 0;
        if (h) {
            v = h->val;
            if (TreeNode *p = h->left) {
                while (p->right && p->right != h) 
                    p = p->right;

                if (p->right) {
                    h = h->right;
                    p->right = NULL;
                } 
                else {
                    p->right = h;
                    h = h->left;
                }
            } 
            else {
                h = h->right;
            }
        }
        return v;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool o = true;
        while (p || q) {
            if (!(p&&q)) o = false;
            if (m(p) != m(q)) o = false;
        }
        return o;
    }
};
