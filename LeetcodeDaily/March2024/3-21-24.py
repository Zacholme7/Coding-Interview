# link: https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21
# difficulty: easy
# date solved: march 21, 2024

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head):
        prev = None

        while head:
            tmp = head
            head = head.next
            tmp.next = prev
            prev = tmp

        return prev
