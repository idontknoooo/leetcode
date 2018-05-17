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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *left = head, *cur = head, *right = head->next;
        while(right){
            cur->next = left;
            left = cur;
            cur = right;
            right = right->next;
        }
        cur->next = left;
        return cur;
    }
};
