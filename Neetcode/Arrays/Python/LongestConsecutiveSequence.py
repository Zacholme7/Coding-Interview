# Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
# Difficulty: Medium
# Date solved: Sept 23, 2023
# Solution
# pretty simple problem and I had the right idea from the start
# the main thing here is that we want to be able to check 
# if a number exists in the list as fast as possible, this can
# be done by turing it into a set which will give us constant access
# on average. We know that there is a start of an interval when
# the number does not have a left neighbor. So we check this first
# and if it is true then we can check all numbers following the 
# current number and keep track of the length of the interval
class Solution:
    def longestConsecutive(self, nums):
        numSet = set(nums)
        longest = 0

        for num in nums:
            if num - 1 not in numSet:
                length = 0
                while num + length in numSet:
                    length += 1
                longest = max(longest, length)
        return longest





if __name__ == "__main__":
    x = Solution()
    print(x.longestConsecutive([9,1,4,7,3,-1,0,5,8,-1,6]))

