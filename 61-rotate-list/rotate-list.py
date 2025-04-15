# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # get list length
        if not head or k == 0:
            return head
        tail = head
        ll_len = 1
        
        while tail.next:
            tail = tail.next
            ll_len += 1
        k = k%ll_len
        if ll_len == 1 or ll_len == k or k == 0:
            return head
        new_tail = head
        for _ in range(ll_len-k-1):
            new_tail = new_tail.next
        new_head = new_tail.next
        new_tail.next = None
        tail.next = head
        head = new_head
        return new_head

        
        
        