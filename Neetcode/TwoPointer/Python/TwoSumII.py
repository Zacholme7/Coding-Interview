# Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
# Difficulty: Medium
# Date solved: May 7, 2023
# Solution
# this is the same as two sum except here we can take advantage of the
# property that the array is sorted. We can have a left and a right pointers
# and we know that there is exactly one solution. We understand that if we sum the 
# left and right elements, it will either be the target, be less than the target,
# or be greater than the target. Using this, if is is the target we have found our numbers,
# if is is greater than the target that means we need a smaller number so we move our right pointer,
# and if it is less than the target that means we need a bigger number so we move our left pointer,
# eventually the two numbers will equal the target

class Solution:
    def twoSum(self, numbers, target):
        left = 0
        right = len(numbers) - 1
        while left < right:
            currSum = numbers[left] + numbers[right]
            if currSum == target:
                return [left + 1, right + 1]
            if currSum > target:
                right -= 1
            else:
                left += 1
        return [-1, -1]


