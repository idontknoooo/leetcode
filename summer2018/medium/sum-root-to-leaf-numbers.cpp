// dfs
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int& res, int num){
        num = num * 10 + root->val;
        if(root->left) dfs(root->left, res, num);
        if(root->right) dfs(root->right, res, num);
        if(!root->left && !root->right) res += num;
    }
};

// bfs
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int num = p.second * 10 + p.first->val;
            if(p.first->left) q.push({p.first->left, num});
            if(p.first->right) q.push({p.first->right, num});
            if(!p.first->left && !p.first->right) res += num;
        }

        return res;
    }
};

// 3ms
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
    void reSumNumbers(TreeNode* root, int& sum)
    {
        int val = root->val;
        sum *= 10;
        sum += val;
        if(root->left == NULL && root->right == NULL)
            return ;
        if(root->left != NULL && root->right == NULL)
        {
            reSumNumbers(root->left, sum);
            return ;
        }
            
        if(root->left == NULL && root->right != NULL)
        {
            reSumNumbers(root->right, sum);
            return ;
        }
        
        int sum1 = sum;
        int sum2 = sum;
        reSumNumbers(root->left, sum1);
        reSumNumbers(root->right, sum2);
        sum  = sum1 + sum2;
    }
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int sum = 0;
        reSumNumbers(root, sum);
        return sum;
    }
};
