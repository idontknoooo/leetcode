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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode *> stack;
        while (root || !stack.empty()) {
            if (root) {
                result.push_back(root->val);
                stack.push_back(root);
                root = root->left;
            } else {
                root = stack.back();
                stack.pop_back();
                root = root->right;
            }
        }
        return result;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;

        if (root == nullptr)
            return ret;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* tp = st.top();
            st.pop();
            ret.push_back(tp->val);
            if (tp->right != nullptr) st.push(tp->right);
            if (tp->left != nullptr) st.push(tp->left);
        }

        return ret;        
    }
};
