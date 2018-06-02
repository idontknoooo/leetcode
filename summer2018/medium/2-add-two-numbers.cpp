// My solution 61ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = l1;
        int carry = 0;
        while(l1 || l2) {
            if(l1 && l2) {
                l1->val += l2->val + carry;
                if(l1->val > 9) {
                    l1->val %= 10;
                    carry = 1;
                } else carry = 0;
                if(l1->next && !l2->next || l1->next && l2->next) {
                    l1 = l1->next;
                    l2 = l2->next;
                } else if(!l1->next && l2->next) {
                    l1->next = l2->next;
                    l2       = NULL;
                    l1       = l1->next;
                } else break;
            } else if(l1 && !l2) {
                l1->val += carry;
                if(l1->val > 9) {
                    l1->val %= 10;
                    carry = 1;
                } else carry = 0;
                if(l1->next) l1 = l1->next;
                else break;
            }
        }
        if(carry) l1->next = new ListNode(1);
        return l3;
    }
};


// 53ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *h1=&dummy;
        int sum_over=0;
        while(l1 || l2 || sum_over){
            if(l1){
                sum_over += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum_over += l2->val;
                l2 = l2->next;
            }
            h1->next = new ListNode(sum_over%10);
            h1 = h1->next;
            sum_over /= 10;
        }
        return dummy.next;
    }
};
