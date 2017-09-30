// Fast node will eventually meet slower node
public boolean hasCycle(ListNode head) {
    if (head == null || head.next == null) {
        return false;
    }
    ListNode slow = head;
    ListNode fast = head.next;
    while (slow != fast) {
        if (fast == null || fast.next == null) {
            return false;
        }
        slow = slow.next;
        fast = fast.next.next;
    }
    return true;
}
// Hashset C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> nodesSeen;
        while (head) 
        {
            if (nodesSeen.find(head)!=nodesSeen.end()) 
                return true;
            else
                nodesSeen.insert(head);
            if(head) head = head->next;
        }
        return false;
    }
}; 
