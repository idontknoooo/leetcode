// 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
  //  find mid position
  ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
  // partation
        fast = slow->next;
        slow->next = NULL;
        slow = sortList(head);
        fast = sortList(fast);
  // merge
        ListNode **now = &head;
        while(slow && fast) {
            if(slow->val < fast->val) {
                *now = slow;
                slow = slow->next;
            }
            else {
                *now = fast;
                fast = fast->next;
            }
            now = &(*now)->next;
        }
        if(slow) *now = slow;
        if(fast) *now = fast;
        return head;
    }
};

// 45ms
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
    /*void printlist(ListNode* head) {
        while(head) {
            cout<< head->val << "->";
            head = head->next;
        }
        cout << endl;
        return;
    }*/
    ListNode* quickSortList(ListNode* head, ListNode *end) {
        ListNode *cur = NULL, *next = NULL, *flag = NULL, *pre = NULL;
        ListNode *temp = NULL, *temp1 = NULL;
        //printlist(head);
        if(head && head != end) {
            cur = head->next;
            flag = head;
            pre = head;
        } else {
            return head;
        }
        
        while(cur && cur != end) {
            next = cur->next;
            if(cur->val < flag->val) {
                cur->next = head;
                pre->next = next;
                head = cur;
                if(!temp) temp = cur;
            } else if (cur->val == flag->val) {
                pre->next = next;
                if(temp) {
                    cur->next = temp->next;
                    temp->next = cur;
                } else {
                    cur->next = head;
                    temp = cur;
                    head = cur;
                }
            }else {
                pre = cur;
            }
            cur = next;
        }

        next = flag->next;
        flag->next = NULL;
        if((temp && temp->next == flag) || !temp)
            head = quickSortList(head, flag);
        else 
            head = quickSortList(head, temp->next);
        next = quickSortList(next, end);
        flag->next = next;

        return head;
    }
    ListNode* sortList(ListNode* head) {
        head = quickSortList(head, NULL);
        return head;
    }
};
