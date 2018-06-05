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
        ListNode* less = new ListNode(-1); // Make prefix
        ListNode* more = new ListNode(-1);
        ListNode* less_p = less, * more_p = more;
        while(head) {
            if(head->val < x) {
                less_p->next = head; //new ListNode(head->val);
                less_p = less_p->next;
            } else {
                more_p->next = head; //new ListNode(head->val);
                more_p = more_p->next;
            }
            head = head->next;
        }
        more_p->next = NULL;       // break the loop
        less_p->next = more->next;
        return less->next;
    }
};
