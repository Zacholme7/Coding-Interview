# Link: https://leetcode.com/problems/two-sum/
# Difficulty: Easy
# Date solved: Sept 23, 2023
# Solution
# we want to find the two numbers that add up to the given target
# we can track each number and its index in a dictionary. On each iteration
# we take the current number and subtract it by out target to see what other
# number we need to get the sum. We then look in the dictionary to see if
# we have previoulsy seen the number that we need and if we have we return the 
# indicies of the two numbers, else we add the current number and its index into
# the dictionary and check the next numbers

class Solution:
    def twoSum(self, nums, target):
        numDict = {}
        for idx in range(len(nums)):
            remaining = target - nums[idx]
            if remaining in numDict:
                return [numDict[remaining], idx]
            else:
                numDict[nums[idx]] = idx

        return [-1, -1]
