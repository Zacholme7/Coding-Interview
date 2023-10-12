# Link: https://leetcode.com/problems/product-of-array-except-self/submissions/729721930/
# Difficulty: Medium
# Date solved: Sept 25, 2023
# Solution
# the solution is pretty straighforward but it is a bit tricky to implement
# we want to have the ith index be the product of all numbers before and after it
# we can do this by going once through the array forward and once through it backwards 
# and each index will maintain a tracker of all of the numbers before then after.
# so we have a res array that is one and from the 1st index to the end the value
# of the ith index will be the product of all numbers before it. We then repeat this 
# process going back and that will give us the correct array

class Solution:
    def productExceptSelf(self, nums):
        resArr = [1] * len(nums)
        for idx in range(1, len(nums)):
            resArr[idx] = nums[idx-1] * resArr[idx - 1]

        for idx in range(len(nums) - 2, -1, -1):
            resArr[idx] = resArr[idx] * nums[idx+1]
            nums[idx] = nums[idx] * nums[idx + 1]
        return resArr
