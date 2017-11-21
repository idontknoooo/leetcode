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
//     void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
//     if(!root->left && !root->right) {
//         result.push_back(t);
//         return;
//     }

//     if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
//     if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
// }

// vector<string> binaryTreePaths(TreeNode* root) {
//     vector<string> result;
//     if(!root) return result;
    
//     binaryTreePaths(result, root, to_string(root->val));
//     return result;
// }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        traverse(root, "", ans);
        return ans;
    }
    void traverse(TreeNode * node, string tmp, vector<string> & ans) {
        if (node == nullptr) return;
        tmp += (tmp.size() ? "->" : "") + to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(tmp);
            return;
        }
        traverse(node->left, tmp, ans);
        traverse(node->right, tmp, ans);
    }
};