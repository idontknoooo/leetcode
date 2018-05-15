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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a && b){
            a = a->next;
            b = b->next;
        } 
        ListNode *a1 = headA, *b1 = headB;
        if(a){
            while(a1 && b1){
                if(a1 == b1) return a1;
                if(a) a = a->next;
                else b1 = b1->next;
                a1 = a1->next;
            }
        } else {
            while(a1 && b1){
                if(a1 == b1) return a1;
                if(b) b = b->next;
                else a1 = a1->next;
                b1 = b1->next;
            }
        }
        return NULL;
    }
};
