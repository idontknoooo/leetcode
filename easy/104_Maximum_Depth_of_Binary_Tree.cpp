/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return (!root)? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
}
;
// BFS solution
// Traver until last layer, use 'res' to count number of layers
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop(); // Pop previous layer's nodes
            
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
    }
    return res;
}
