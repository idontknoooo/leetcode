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
         
        while(head && head->val==val)
            head = head->next;
        ListNode* tmp = head;
        while(tmp && tmp->next)
        {
            if(tmp->next->val==val)
            {
                if(tmp->next->next)
                    tmp->next = tmp->next->next;
                else
                    tmp->next = nullptr;
            }
            else 
            {
                if(tmp)
                    tmp = tmp->next;
            }                
        }
        return head;
    }
};