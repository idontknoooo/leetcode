// 10 ms
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0, i = 0;
        int end = inorder.size();
        return dfs(preorder, inorder, p, i, end);
    }
    
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& p, int& i, int end)
    {
        if(i < inorder.size() && (end == inorder.size() || inorder[i] != preorder[end]))
        {
            TreeNode* ret = new TreeNode(preorder[p++]);
            ret->left = dfs(preorder, inorder, p, i, p-1);
            ++i;
            ret->right = dfs(preorder, inorder, p, i, end);
            return ret;
        }
        else return NULL;
    }
};
