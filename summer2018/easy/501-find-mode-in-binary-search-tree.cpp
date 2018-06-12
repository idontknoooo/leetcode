// My solution using unordered_map
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
    void help(TreeNode* root, unordered_map<int, int>& um){
        if(root){
            ++um[root->val];
            help(root->left, um);
            help(root->right, um);
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> um;
        help(root, um);
        int val, amt = 0;
        for(auto p : um){
            if(p.second > amt) amt = p.second, val = p.first;
        }
        vector<int> ans;
        for(auto p : um){
            if(p.second == amt) ans.push_back(p.first);
        }
        return ans;
    }
};


// 15 ms
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
    vector <int> result;
    TreeNode* prev = NULL;
    bool first_dup_found = false;
    int max_count = 1;
    int count = 1;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev)  {
            if (root->val == prev->val) {
                count ++;
            } else {
                if (count == max_count) {
                    result.push_back(prev->val);
                } else if (count > max_count) {
                    max_count = count;
                    result.clear();
                    result.push_back(prev->val);
                }
                count = 1;
            }
        }
        prev = root;
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return result;
        inorder(root);
        
        if (count == max_count) {
            result.push_back(prev->val);
        } else if (count > max_count) {
            max_count = count;
            result.clear();
            result.push_back(prev->val);
        }
        
        return result;
    }
};


// 14ms
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
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        TreeNode* pre = NULL;
        int gmax      = INT_MIN;
        int cnt       = 0;
        helper(root, res, pre, cnt, gmax);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res, TreeNode*& pre, int& cnt, int& gmax){
        if(!root) return ;
        helper(root->left,res,pre,cnt,gmax);
        if(pre!= NULL)
            cnt = pre->val == root->val ?  cnt+1: 1;
        else
            cnt++;
        if(cnt >= gmax ){
            if(cnt > gmax) res.clear();
            res.push_back(root->val);
            gmax = cnt;
        }
        pre = root;
        helper(root->right,res,pre,cnt,gmax);
    }
};

// O(1) space
class Solution
{
public:
  std::vector<int> findMode(TreeNode *root)
  {
    std::vector<int> res;
    int preVal = 0, count = 1, maxCount = 0;
    inorder(root, preVal, count, maxCount, res);
    return res;
  }

private:
  void inorder(TreeNode *root, int& preVal, int& count, int& maxCount, std::vector<int>& modes)
  {
    if (root != NULL)
    {
      inorder(root->left, preVal, count, maxCount, modes);
      if (!modes.empty())
      {
        if (root->val != preVal)
          count = 1;
        else
          ++count;
      }
      if (maxCount <= count)
      {
        if (maxCount < count)
          modes.clear();
        modes.push_back(root->val);
        maxCount = count;
      }
      preVal = root->val;
      inorder(root->right, preVal, count, maxCount, modes);
    }
  }
};

