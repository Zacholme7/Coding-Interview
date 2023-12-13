# Link: https://leetcode.com/problems/permutations/description/
# Difficulty: Medium
# Date Solved: December 13, 2023

class Solution:
    def helper(tracker, nums, res):
        if len(tracker) == len(nums):
            res.append(tracker.copy())
            return

        for num in nums:
            if num in tracker:
                continue
            tracker.append(num)
            self.helper(tracker, nums, res)
            tracker.pop()

    def permute(self, nums):
        nums = []
        self.tracker([], nums, res)
        return nums
