# Link: https://leetcode.com/problems/merge-two-sorted-lists/submissions/539638774/
# Difficulty: Easy
# Date Solved: Oct 4, 2023
# Solution
# this is relatively simple. We just want to construct a new list out
# of the two that we have. We have a tmp node to return and a dummy
# that will be tracking and creating the list. While list1 and list2
# we want to find which head is smaller, set the dummy.next to the head,
# advance the head, then advance the dummy. We do this for each case. At the
# end we just want to add the remaining of whatever list is left and return 
# the tmp.next which is tracking the list

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1, l2):
        tmp = dummy = ListNode(0)
        
        while l1 and l2:
            if l2.val <= l1.val:
                dummy.next = l2
                l2 = l2.next
                dummy = dummy.next
            else:
                dummy.next = l1
                l1 = l1.next
                dummy = dummy.next
        dummy.next = l1 or l2
        return tmp.next



