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
    ListNode* reverseList(ListNode* head) {
        // ListNode* pre = head, *post = head;
        // if(pre)
        // {
        //     ListNode* tmp;
        //     if(pre->next)
        //     {
        //         post = post->next;
        //         pre->next = NULL;
        //         cout << pre->val << endl;
        //         while(post && tmp)
        //         {
        //             tmp = post->next;
        //             post->next = pre;
        //             //cout << post->val << post->next->val << endl;
        //             pre = post;
        //             if(tmp)
        //                 post = tmp;
        //         }
        //     } 
        // } 
        // //cout << post->val << " " << post->next->val << endl;
        // head = post;
        // while(post)
        // {
        //     cout << post->val << " ";
        //     post = post->next;
        // }
        // return head;
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }
};