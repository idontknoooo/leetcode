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
        if(!head) return head;
        ListNode* res = head, *cur = res;
        while(head) {
            if(cur->val != head->val) {
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
        }
        cur->next = head;
        return res;
    }
};
