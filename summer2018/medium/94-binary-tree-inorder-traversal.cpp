// my solution 3ms
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
    vector<int> ans;
public:
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};


// 2ms non-recursive
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> result;
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* p = cur->left;
                while (p->right != cur && p->right != nullptr)
                {
                    p = p->right;
                }
                
                if (!p->right)
                {
                    p->right = cur;
                    cur = cur->left;
                }
                else
                {
                    p->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
