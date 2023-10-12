# Link: https://leetcode.com/problems/binary-search/
# Difficulty: Easy
# Date Solved: Oct 5, 2023
# Solution
# Just the classical binary search. Init our left and right pointers
# and calcualte the midpointe, check if the mid is the value and if
# not move the left and right pointers one past or one behind the 
# midpoint

class Solution:
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1
