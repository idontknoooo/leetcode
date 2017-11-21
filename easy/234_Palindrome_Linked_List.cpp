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
    // bool isPalindrome(ListNode* head) {
    //     if(head==NULL||head->next==NULL)
    //         return true;
    //     ListNode* slow=head;
    //     ListNode* fast=head;
    //     while(fast->next!=NULL&&fast->next->next!=NULL){
    //         slow=slow->next;
    //         fast=fast->next->next;
    //     }
    //     slow->next=reverseList(slow->next);
    //     slow=slow->next;
    //     while(slow!=NULL){
    //         if(head->val!=slow->val)
    //             return false;
    //         head=head->next;
    //         slow=slow->next;
    //     }
    //     return true;
    // }
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* pre=NULL;
    //     ListNode* next=NULL;
    //     while(head!=NULL){
    //         next=head->next;
    //         head->next=pre;
    //         pre=head;
    //         head=next;
    //     }
    //     return pre;
    // }
//     bool isPalindrome(ListNode* head) {
//         // reported by test case, null pointer should be considered
//         // as a palindrome
//         if (head == NULL){
//             return true;
//         }
//         if (head->next == NULL){
//             return true;
//         }
//         ListNode *cursor_l, *cursor_r, *cursor_m, *middle_mark;
//         cursor_l = head;
//         cursor_r = head;
//         while (cursor_r->next != NULL && cursor_r->next->next != NULL){
//             cursor_l = cursor_l->next;
//             cursor_r = cursor_r->next->next;
//         }
        
//         if (cursor_r->next == NULL){
//             // odd number of nodes
//             middle_mark = cursor_l;
//             cursor_m = cursor_l->next;
//             middle_mark->next = NULL;
//         }
//         else{
//             // even number of nodes
//             middle_mark = new ListNode(0);
//             cursor_m = cursor_l->next;
//             cursor_l->next = middle_mark;
//             cursor_l = middle_mark;
//         }
        
//         cursor_r = cursor_m->next;
        
//         while (cursor_r != NULL){
//             cursor_m->next = cursor_l;
//             cursor_l = cursor_m;
//             cursor_m = cursor_r;
//             cursor_r = cursor_r->next;
//         }
//         cursor_m->next = cursor_l;
        
//         cursor_l = head;
//         cursor_r = cursor_m;
//         while (cursor_l != cursor_r){
//             if (cursor_l->val != cursor_r->val){
//                 return false;
//             }
//             cursor_l = cursor_l->next;
//             cursor_r = cursor_r->next;
//         }
//         return true;
//     }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};