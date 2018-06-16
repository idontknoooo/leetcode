// 5ms beat 88%
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(m==n || !head){return head;}
      ListNode before_head(0);
      ListNode* p = &before_head;
      before_head.next = head;
      for(int i=0; i<m-1; i++){
        p = p->next;
      }
      ListNode* curr = p->next;
      for(int i=0; i<n-m; i++){
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = p->next;
        p->next = tmp;
      }
      return before_head.next;
    }
};


// my solution 5ms beat 88%
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 1;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *beforeStart = newHead;//m==1? NULL : head;
        while(i < m) {
            beforeStart = beforeStart->next;
            ++i;
        }
        ListNode *prev = NULL, *cur = beforeStart->next, *tmp, *newTail = cur;
        while(i <= n) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            ++i;
        }
        beforeStart->next = prev;
        newTail->next = cur;
        return newHead->next;
    }
};
