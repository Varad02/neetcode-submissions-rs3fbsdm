# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        node = head
        delNode = dummy

        for _ in range(n):
            node = node.next

        while node:
            node = node.next
            delNode = delNode.next

        delNode.next = delNode.next.next
        return dummy.next        