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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<int> level;
        vector<vector<int>> re;
        if(!root) return re;
        
        level.push_back(root->val);
        re.push_back(level);
        level.clear();
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            for(int i = 0, n = q.size(); i < n; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if(p->left){
                    level.push_back(p->left->val);
                    q.push(p->left);
                }    
                if(p->right){
                    level.push_back(p->right->val);
                    q.push(p->right);
                }
            }
            if(!level.empty())
                re.push_back(level);
            level.clear();
        }
        
        std::reverse(re.begin(), re.end());
        return re;
    }
};

 // 递归写法
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<vector<int>> reverse_res;
        levelorder(root, 0, res);
        
        vector<vector<int>>::reverse_iterator it;
        for (it=res.rbegin(); it!=res.rend(); it++){
            reverse_res.push_back(*it);
        }
        return reverse_res;
    }
    
    void levelorder(TreeNode *root, int level, vector<vector<int>> &res){
        if(!root) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if(root->left) levelorder(root->left, level+1, res);
        if(root->right) levelorder(root->right, level+1, res);
    }
    