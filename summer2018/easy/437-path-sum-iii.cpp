class Solution {
    unordered_map<int, int> kv{{0,1}};
public:
    int pathSum(TreeNode* root, int sum) {
        return rec(root, 0, sum);
    }
    
    int rec(TreeNode* root, int csum, int targ) {
        if (!root) return 0;
        csum+=root->val;
        kv[csum] += 1;
        int lc = rec(root->left, csum, targ);
        int rc = rec(root->right, csum, targ);
        kv[csum] -= 1;
        return kv[csum-targ] + lc + rc;
    }
};


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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int sumUp(TreeNode* root, int pre, int& sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
