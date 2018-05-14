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
    TreeNode* helper(int start, int end, vector<int> vec) {
        if(start > end){
            return NULL;
        } else {
            int pos = (start + end) / 2;
            TreeNode* cur     = new TreeNode(vec[pos]);
            cur->left = helper(start, pos-1, vec);
            cur->right = helper(pos+1, end, vec);
            return cur;
        }    
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return nullptr;
        TreeNode *head;
        head = helper(0, nums.size()-1, nums);
        return head;
    }
};
