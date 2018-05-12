/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* result = new ListNode(-1);
        ListNode* head = result;
        while(l1 && l2){
           if(l1->val < l2->val){
               result->next = l1;
               l1           = l1->next;
           } else {
               result->next = l2;
               l2           = l2->next;
           }
           result = result->next;  
        }
        result->next = l1? l1 : l2;
        return head->next;
    }
};
