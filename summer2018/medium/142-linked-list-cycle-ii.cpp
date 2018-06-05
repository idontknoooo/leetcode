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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        if(head->next==head) return head;
        ListNode *p = head, *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        if(fast->next==NULL || fast->next->next==NULL) return NULL;
        if(p==fast) return p;
        while(fast->next!=NULL && p->next!=NULL)
        {
            fast=fast->next;
            p=p->next;
            if(p==fast)
                break;
        }
        return ( fast==p && p!=head )? p : NULL;
    }
};


// 
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return NULL;
        }
        ListNode* pFast=head->next->next;
        ListNode* pSlow=head->next;
        while(pFast!=pSlow){
            if(pFast->next==NULL||pFast->next->next==NULL){
                return NULL;
            }
            pFast=pFast->next->next;
            pSlow=pSlow->next;
        }
        
        ListNode* start=head;
        while(start!=pSlow){
            start=start->next;
            pSlow=pSlow->next;
        }
        
        return pSlow;
    }
};
