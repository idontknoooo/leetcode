// Best solution 
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//reverse list 把后半段的原地链表反转然后和前半段进行比较 若没空间要求，则可以用vector
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    if (head == NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL &&fast->next->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    ListNode* rev = reverse(head2);
    //判断是否是同一个list
    while (head != NULL && rev != NULL)
    {
      if (head->val != rev->val)
        return false;
      head = head->next;
      rev = rev->next;
    }
    return true;
  }

    
  /*  ListNode* reverse(ListNode* head)
    {
        if(head == NULL) return NULL;
        ListNode* pre = head;
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* p = newHead->next;
        ListNode* q;
        while(p->next!= NULL)//reverse list
        {
            q = p->next;
            p->next = q->next;
            q->next = newHead->next;
            newHead->next = q;
        }
        return newHead->next;
    }*/
    ListNode* reverse(ListNode* head)
    {
    if(head == NULL) return NULL;
        
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* p = newHead->next;
        ListNode* temp;
        while(p->next != NULL)
        {
            temp = p->next;
            p->next = temp->next;
            temp->next = newHead->next;
            newHead->next = temp;
        }
        return newHead->next;
    }
};
