// My solution 26ms beat 92%
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
    bool sameTree(TreeNode* s, TreeNode* t) {
        if(s && t && s->val == t->val){
            return sameTree(s->left, t->left) && sameTree(s->right, t->right);
        } else if (!s && !t) { // If both doesnt' exist, meaning reach the end, then return true
            return true;
        } else {  // If one is the end, the other is not, return false
            return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s && t) { // If both s & t exist, check whether same tree or isSubtree on left or right
            return sameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        } else if (!s && !t) { // If both doesnt' exist, meaning reach the end, then return true
            return true;
        } else { // If one is the end, the other is not, return false
            return false;
        }
    }
};
