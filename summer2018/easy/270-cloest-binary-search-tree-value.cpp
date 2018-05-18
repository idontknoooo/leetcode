// Iterative method
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
         int res = root->val;
        while(root){
            if(abs(res - target) > abs(root->val - target)){
                res = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};

// Recursive method
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        auto child = target < root->val ? root->left : root->right;
        if (child == NULL) return a;
        int b = closestValue(child,target);
        return (abs(a-target)  < abs(b-target)) ? a : b;
    }
};
