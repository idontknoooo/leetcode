// my solution 7ms beat 88%
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1); // Make prefix
        ListNode* large = new ListNode(-1);
        ListNode* small_p = small, * large_p = large;
        while(head) {
            if(head->val < x) {
                small_p->next = head; //new ListNode(head->val);
                small_p = small_p->next;
            } else {
                large_p->next = head; //new ListNode(head->val);
                large_p = large_p->next;
            }
            head = head->next;
        }
        large_p->next = NULL;       // break the loop
        small_p->next = large->next;
        return small->next;
    }
};
