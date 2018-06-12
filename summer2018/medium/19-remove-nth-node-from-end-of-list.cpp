// my solution 10ms beat 70%
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = new ListNode(-1);
        tmp->next = head;
        
        ListNode* second = tmp, * third = tmp;
        
        int len = -1;
        while(tmp) {
            tmp = tmp->next;
            ++len;
        }
        
        if(len == 1) {return NULL;}
        len -= n;
        while(len-- && second) second = second->next;
        
        second->next = second->next->next;
        return third->next;
    }
};

// One pass use pointer of pointer
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i) t2 = t2->next;
        while(t2->next != NULL) {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};


// One pass use pointer only
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head, *tmp1 = head;
        while(n--) tmp = tmp->next;
        if(!tmp) return head->next;
        while(tmp->next) {
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp1->next->next;
        return head;
    }
};


// My new one pass
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* slow = new ListNode(-1), *fast = slow, *ans = slow;
        slow->next = head;
        int i = 0;
        while(fast) {
            fast = fast->next;
            if(i++ > n) slow = slow->next;
        }
        slow->next = slow->next->next;
        return ans->next;
    }
};
