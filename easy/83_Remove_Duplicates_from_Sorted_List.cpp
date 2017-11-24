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


// This one faster, since it check all dupicates at one time
ListNode* deleteDuplicates(ListNode* head) {
    if(!head)return head;
    ListNode*h=head;
    while(h)
    {
        while(h->next&&h->val==h->next->val)
        {
            h->next=h->next->next;
        }
        h=h->next;
    }
    return head;
}