// 11ms
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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        helper(root, result, current, sum);
        return result;
    }

    void helper(TreeNode* root, std::vector<std::vector<int>>& result, std::vector<int>& current, int target_sum) {

        if (!root) {
            return;
        }

        current.push_back(root->val);

        // leaf
        if (!root->left && !root->right) {
            int current_sum = 0;
            for (int val : current) {
                current_sum += val;
            }

            if (current_sum == target_sum) {
                result.push_back(current);
            }
        }

        helper(root->left, result, current, target_sum);
        helper(root->right, result, current, target_sum);

        current.pop_back();
    }
};

// 11ms
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
       if(!root) return paths;
        vector<int>path;
        
        helper(root,sum,path,paths);
        return paths;
    }
private:
        void helper(TreeNode *node, int sum,vector<int> & path, vector<vector<int>> &paths){
        if(!node)return ;    
        path.push_back(node->val);
        if(!node->right && !node->left&& sum == node->val)
            paths.push_back(path);
        helper(node->left,sum - node->val,path,paths);
        helper(node->right,sum - node->val,path, paths);
        path.pop_back();
    }
};
