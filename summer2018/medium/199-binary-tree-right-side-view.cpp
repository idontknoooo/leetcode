//  4ms
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
    void helper(TreeNode * root, int level, vector<int> & res) {
        if(!root) return;
        if(level == res.size()){
            res.push_back(root -> val);
        } else {
            res[level] = root -> val;
        }
        helper(root -> left, level + 1, res);
        helper(root -> right, level + 1, res);  
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        helper(root, 0, res);
        return res;
    }
};


// 4ms
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> treeQueue;
        TreeNode* curr;
        int levelNodeCnt;
        
        treeQueue.push(root);
        while(!treeQueue.empty())
        {
            levelNodeCnt = treeQueue.size();
            while(--levelNodeCnt >= 0)
            {
                curr = treeQueue.front();
                treeQueue.pop();
                if(curr->left)
                {
                    treeQueue.push(curr->left);
                }
                if(curr->right)
                {
                    treeQueue.push(curr->right);
                }                
            }
            res.push_back(curr->val);//now curr point to the rightest node of the level
        }
        return res;           
    }
};
