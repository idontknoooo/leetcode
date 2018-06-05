// 18ms
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootPos = postorder.size() - 1;
        return helper(inorder, 0, inorder.size() - 1, postorder, rootPos);
    }
    
private:
    TreeNode* helper(vector<int>& inorder, int l, int r, vector<int>& postorder, int& end) {
        if(l > r || end < 0)    return nullptr;
        
        int rootVal = postorder[end];
        int rootIndex = find(inorder.begin() + l, inorder.begin() + r, rootVal) - inorder.begin();
        
        TreeNode* root = new TreeNode(rootVal);

        end --;
        root->right = helper(inorder, rootIndex + 1, r, postorder, end);
        root->left = helper(inorder, l, rootIndex - 1, postorder, end);
        return root;
    }
};



// 10ms
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        return buildTreeRe(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* buildTreeRe(vector<int>& inorder, vector<int>& postorder, int i1, int i2, int p1, int p2){
        if(p1>p2)
            return NULL;
        TreeNode* root = new TreeNode(postorder[p2]);
        int pos;
        for(int i = i2;i>=i1;i--){
            if(inorder[i]==root->val){
                pos = i;
                break;
            }
        }
        root->left = buildTreeRe(inorder, postorder, i1, pos-1, p1, p1+pos-i1-1);
        root->right = buildTreeRe(inorder, postorder, pos+1, i2, p2-i2+pos, p2-1);
        
        return root;
    }
};
