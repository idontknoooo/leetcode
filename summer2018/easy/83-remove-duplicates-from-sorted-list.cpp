/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Double pointer
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode* fast = head, * slow = head;
        while(fast){
           if(slow->val != fast->val){
                slow->next = fast;
                slow = slow->next;  
           } 
           fast = fast->next;  
        }
        slow->next = fast;
        return head;    
    }
};


// Single pointer
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};
