// My solution 21ms beat 32%
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
    string ans = "";
public:
    string tree2str(TreeNode* t) {
        if(t) {
            ans += to_string(t->val); 
            
            if(t->left || t->right) ans += "(";
            tree2str(t->left);
            if(t->left || t->right) ans += ")";
                
            if(t->right) ans += "(";
            tree2str(t->right);
            if(t->right) ans += ")";
            
            return ans;
        } else {
            return "";
        }
    }
};
