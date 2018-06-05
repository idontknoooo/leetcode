// my solution 9ms beat 99%
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head && !head->next || !head) return head;
        ListNode* h = new ListNode(-1);
        h->next     = head;
        ListNode* p = h;
        while(p && p->next && p->next->next) {
            if(p->next->val == p->next->next->val) {
                ListNode* tmp = p->next->next;
                while(tmp && p->next->val == tmp->val) 
                    tmp = tmp->next;
                p->next = tmp;
            } else p = p->next;
        }
        return h->next;
    }
};
