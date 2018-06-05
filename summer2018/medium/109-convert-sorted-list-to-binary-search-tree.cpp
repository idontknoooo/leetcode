// 23ms
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        vector<int> list;
        while (head) {
            list.emplace_back(head->val);
            head = head->next;
        }
        int begin = 0, end = list.size() - 1;
        TreeNode* res = arrayToBST(begin, end, list);
        return res;
    }
    
    TreeNode* arrayToBST(int begin, int end, const vector<int> &list) {
        if (begin > end) return NULL;
        if (begin == end) return (new TreeNode(list[begin]));
        int mid = (begin + end + 1) / 2;
        TreeNode* node = new TreeNode(list[mid]);
        node->left = arrayToBST(begin, mid-1, list);
        node->right = arrayToBST(mid+1, end, list);
        return node;
    }
};

// 23ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        return dfs(head,NULL);
    }
    
    TreeNode* dfs(ListNode* head , ListNode* tail){
        
        
        if(head==tail)
            return NULL;
        
        if( head->next == tail ){ 
        TreeNode *root = new TreeNode( head->val );
        return root;
      }
        
        ListNode *slow,*fast;
        slow = fast =head;
        
        while(fast!=tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = dfs(head,slow);
        root->right = dfs(slow->next,tail);
        
        return root;
    }
    
    
    
};
