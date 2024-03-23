# link: https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23
# difficulty: medium
# date solved: march 24, 2024
# solution writeup: this just combines some easy problems we have seen before. Get the middle of the list
# using a fast and slow pointer, reverse the second list, then merge them together

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverse(self, head):
        if not head:
            return None
        prev = None
        curr = head
        nextNode = None
        while curr:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev

    def merge(self, list1, list2):
        while list2:
            nextNode = list1.next
            list1.next = list2
            list1 = list2
            list2 = nextNode

    def reorderList(self, head):
        if not head or not head.next:
            return
        slow = head
        fast = head
        prev = head
        while fast and fast.next:
            prev = slow
            fast = fast.next.next
            slow = slow.next
        prev.next = None
        list1 = head
        list2 = self.reverse(slow)
        self.merge(list1, list2)
