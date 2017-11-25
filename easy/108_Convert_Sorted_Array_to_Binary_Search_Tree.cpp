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
    TreeNode* sortedArrayToBST(vector<int>& num) {
        if(num.size() == 0) return NULL;
        if(num.size() == 1) return new TreeNode(num[0]);
        
        int middle = num.size()/2;
        TreeNode* root = new TreeNode(num[middle]);
        
        vector<int> leftInts(num.begin(), num.begin()+middle);
        vector<int> rightInts(num.begin()+middle+1, num.end());
        
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);
        
        return root;
    }
};

// 9ms beat 100%, instead of using iterator, create helper function using [] as locator
TreeNode* sortedArrayToBST(vector<int>& num){

    if(!num.size()) return NULL;

    // Set up for first node
    int tmp = (num.size())/2;
    TreeNode* tn = new TreeNode(num[tmp]);
    tn->left = helper(tn->left, num, 0, tmp);
    tn->right = helper(tn->right, num, tmp+1, num.size());
    return tn; 
}

TreeNode* helper(TreeNode* tn, vector<int>& num, int start, int end){

    if(start < end){
     int tmp = (end+start)/2;
        tn = new TreeNode(num[tmp]);

     tn->left = helper(tn->left, num, start, tmp);
     tn->right = helper(tn->right, num, tmp+1, end);
        return tn;
    }
    else
     return NULL;
}