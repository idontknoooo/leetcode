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
	// Height for calculation
    int height(TreeNode* root)
    {
        return (!root)? 0 : 1 + max(height(root->left), height(root->right));
    }
	// Orignal function
    bool isBalanced(TreeNode* root) 
    {
		// return true when left & right are balance and left-right <= 1
        return (!root)? true : isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
	}
    
};

// 0ms solution
class Solution {
public:
    
    int treeHight(TreeNode* root){
        if(root==NULL)
            return 0;
        int leftlengh=treeHight(root->left);
        if(leftlengh==-1)
            return -1;
        int rightlengh=treeHight(root->right);
        if(rightlengh==-1)
            return -1;
        if(abs(leftlengh - rightlengh)>1)
            return -1;
        return max(leftlengh,rightlengh)+1;
    }
    
    bool isBalanced(TreeNode* root)
    {
        if(root==NULL)
            return true;
        return treeHight(root)!=-1;
        
    }
};