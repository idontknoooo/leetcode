// 20ms
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root || !root->left) {
            return;
        }
        
        TreeLinkNode* left_rnode = root->left;
        TreeLinkNode* right_lnode = root->right;
        while (left_rnode && right_lnode) {
            left_rnode->next = right_lnode;
            left_rnode = left_rnode->right;
            right_lnode = right_lnode->left;
        }
        connect(root->left);
        connect(root->right);
    }
};

// 18ms
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        connect(root, NULL);
    }
    void connect(TreeLinkNode *root, TreeLinkNode* next) {
        if(root == NULL)
            return;
        root->next = next;
        
        if(root->left == NULL)
            return;
        
        connect(root->left, root->right);        
        if(next == NULL)
            connect(root->right, NULL);
        else
            connect(root->right, next->left);
    }
};
