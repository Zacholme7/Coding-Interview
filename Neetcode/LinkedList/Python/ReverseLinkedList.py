# Link: https://leetcode.com/problems/reverse-linked-list/
# Difficulty: Easy
# Date Solved: Oct 4, 2023
# Solution
# Simple solution, we just have a prev that will track
# behind the head and a temp that will be one ahead so 
# we dont lose the next pointer. set the temp to the next,
# reassign the heads next to the prev, advance both prev
# to the current head and head to temp for the new head

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head): 
        prev = None
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev
