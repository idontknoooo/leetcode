k/**
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<int> level;
        vector<vector<int>> re;
        if(!root) return re;
        
        level.push_back(root->val);
        re.push_back(level);
        level.clear();
        // Use queue for BFS 
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            // for each level, do lots of push and pop
            // n = q.size() fixed # of iteration
            for(int i = 0, n = q.size(); i < n; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                // Search Left side
                if(p->left){
                    level.push_back(p->left->val);
                    q.push(p->left);
                }    
                // Search Right side
                if(p->right){
                    level.push_back(p->right->val);
                    q.push(p->right);
                }
            }
            // As long as level is not empty, add to 're'
            if(!level.empty())
                re.push_back(level);
                // or use: 
                // re.insert(re.begin(), level); // and omit std::reverse at the end.
            level.clear();
        }
        // Reverse
        std::reverse(re.begin(), re.end());
        return re;
    }
};

 // 递归写法
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        
        std::reverse(res.begin(), res.end());
        return reverse_res;
    }
    
    void levelorder(TreeNode *root, int level, vector<vector<int>> &res){
        if(!root) return;
        // If res.size() is not enough, then add space
        if(res.size() == level) res.push_back({});
        // Only add same level values
        res[level].push_back(root->val);
        if(root->left) levelorder(root->left, level+1, res);
        if(root->right) levelorder(root->right, level+1, res);
    }
    