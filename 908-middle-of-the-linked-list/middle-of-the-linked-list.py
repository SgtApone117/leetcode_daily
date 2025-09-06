# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fastNode = head
        slowNode = head
        while fastNode != None and fastNode.next != None:
            fastNode = fastNode.next.next
            slowNode = slowNode.next
        return slowNode
            