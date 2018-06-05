

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        if (root) st.push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top();
        while (node->right || node->left) {
            if (node->right) {
                st.pop();
                st.push(node->right);
                node->right = NULL;
                st.push(node);
            }
            if (node->left) {
                node = node->left;
                st.top()->left = NULL;
                st.push(node);
            }
        }
        int val = node->val;
        st.pop();
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


// 19ms


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> pathnode;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *cur=root;
        while(cur){
            pathnode.push(cur);
            cur=cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !pathnode.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur=pathnode.top();
        pathnode.pop();
        int res=cur->val;
        cur=cur->right;
        while(cur){
            pathnode.push(cur);
            cur=cur->left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


