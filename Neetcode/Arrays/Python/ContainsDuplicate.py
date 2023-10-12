# https://leetcode.com/problems/contains-duplicate/
# Difficulty: Easy
# Date solved: Sept 20, 2023
# Solution:
# can do this problem in a pythonic way, if there is a duplicate in the list
# then we know that the length of the list with no duplicates will be smaller
# than the length of the original list. So we can just convert the original list
# into a set which will get rid of all the duplicates, then we can just compare 
# the sizes and if the sizes are not the same, then we know that we have a duplicate

class Solution:
    def containsDuplicate(self, nums):
        return len(nums) != len(set(nums))


