# Double loop
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None: 
            return head;
        res = head
        while head:
            while head.next and head.val == head.next.val:
                head.next = head.next.next
            head = head.next    
        return res    
