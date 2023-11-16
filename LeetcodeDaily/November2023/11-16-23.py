# Link: https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2023-11-16
# Difficulty: Medium
# Date solved: November 16, 2023

class Solution:
    def findDifferentBinaryString(self, nums):
        # for converting back to binary
        strLen = len(nums[0])

        # this will make all of the binary numbers into ints
        nums = [int(binString, 2) for binString in nums]

        # get the max number
        max = nums[0]
        for num in nums:
            if num > max: max = num

        # convert to set and iterate to max
        numSet = set(nums)
        for num in range(max):
            if num not in numSet:
                return f"{num:0{strLen}b}"
        return f"{num + 1:0{strLen}b}"
                

        



