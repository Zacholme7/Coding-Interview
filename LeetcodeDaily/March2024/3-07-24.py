# link: https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07
# difficulty: easy
# date solved: march 7, 2024

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head):
        first, second = head, head
        while second and second.next:
            first = first.next
            second = second.next.next
        return first
