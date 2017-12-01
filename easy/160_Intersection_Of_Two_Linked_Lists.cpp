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
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1? cur1->next:headB;
            cur2 = cur2? cur2->next:headA;
        }
        return cur1;
    }
};

// Straight forward solution
// As long as 2 list are same length, we can iterate them together
// So, just find the length difference 
// and adjust longer one to same position as the shorter one
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *cur1 = headA, *cur2 = headB;
        int la = 0, lb = 0;
        // Find A's length
        while(cur1){
            cur1 = cur1->next;
            ++la;
        }
        // Find B's length
        while(cur2){
            cur2 = cur2->next;
            ++lb;
        }
        // Reset node
        cur1 = headA, cur2 = headB;
        int diff = abs(la-lb);
        // Adjust longer list
        if(la>lb){
            while(diff>0){
                cur1=cur1->next;
                diff--;
            }
        }else{
            while(diff>0){
                cur2=cur2->next;
                diff--;
            }
        }
        // Iterate together and see if there is a intersect (same node)
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }