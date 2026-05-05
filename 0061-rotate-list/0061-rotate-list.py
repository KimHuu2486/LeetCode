# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None or head.next == None or k == 0:
            return head

        tail = head
        n = 1
        while tail.next != None:
            tail = tail.next
            n += 1

        k = k % n
        if k == 0:
            return head

        tail.next = head
        new_tail_position = n - k - 1
        new_tail = head
        for _ in range(new_tail_position):
            new_tail = new_tail.next

        head = new_tail.next
        new_tail.next = None 
        
        return head
