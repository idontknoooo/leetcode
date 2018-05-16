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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
            head = head->next;
        ListNode* cur = head;
        while(head && head->next){
            if(head->next->val == val)
                head->next = head->next->next;
             else head = head->next;
        }
        return cur;
    }
};
