# # Link: https://leetcode.com/problems/binary-search/
# Difficulty: Easy
# Date Solved: Oct 21, 2023
# Solution
# the trick here is that unless the arary is not sorted, we have an increaseing
# interval and one that is not increasing. We first check to see if the right side 
# is the non increasing one. For example, the mid would be 5 and the right might be 3
# this means that our min is on this side so we move the mid to mid + 1. Otherwise, we
# need to move to the other side and the mid might be the mid so we adjust the right to the mid
class Solution:
    def findMin(self, nums):
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right)// 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        return nums[left]


