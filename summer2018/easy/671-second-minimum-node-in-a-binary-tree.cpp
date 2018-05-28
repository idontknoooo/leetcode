// 3ms my solution
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
    long min1 = INT_MAX, min2 = INT_MAX;
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root){
            if(root->val < min1) {
                min2 = min1;
                min1 = root->val;
            } else if(root->val < min2 && root->val != min1) 
                min2 = root->val;
            findSecondMinimumValue(root->left);
            findSecondMinimumValue(root->right);
        }
        return min2==INT_MAX? -1 : min2;
    }
};


// 2ms
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int ans = minval(root, root->val);
        return ans;
    }
private:
    int minval(TreeNode* p, int first) {
        if (p == nullptr) return -1;
        if (p->val != first) return p->val;
        int left = minval(p->left, first), right = minval(p->right, first);
        // if all nodes of a subtree = root->val, 
        // there is no second minimum value, return -1
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};
