# Link: https://leetcode.com/problems/linked-list-cycle/
# Difficulty: Easy
# Date Solved: Oct 18, 2023
# Solution
# Just have a fast and a slow poitner that will move through the list
# while the fast pointer is still valid and it has a next, move the fast
# two ahead and move the slow one ahead, eventually the fast will lap 
# the slow and they will be on the same node and if they are we will
# be able to see if it has a cycle, othrewise it will hit the end of the list

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

        
