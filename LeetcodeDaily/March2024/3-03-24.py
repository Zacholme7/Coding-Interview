# link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
# difficulty: medium
# date solved: march 3, 2024

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy

        for _ in range(n + 1):
            first = first.next

        while first is not None:
            first = first.next
            second = second.next

        second.next = second.next.next

        return dummy.next
