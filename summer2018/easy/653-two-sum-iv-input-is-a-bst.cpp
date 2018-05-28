// My solution 42ms beat 42%
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
    unordered_map<int, int> um;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root) {
            um[root->val] = 1;
            if(k-root->val != root->val && um[k - root->val]) return true;
            return findTarget(root->left, k) || findTarget(root->right, k);
        } else return false;;
    }
};


// 34ms
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return find1(root, root, k);
    }
private:
    bool find1(TreeNode* root, TreeNode* now, int k) {
      if (now == NULL) return false;
      bool out = false;
      for (TreeNode* r = root; r != NULL;) {
        if (k == 2 * now->val) break;
        if (k == now->val + r->val) {
          out = true;
          break;
        }
        if (k > now->val + r->val) r = r->right;
        else if (k < now->val + r->val) r = r->left;
      }
      return (out || find1(root, now->left, k) || find1(root, now->right, k));
    }
};
