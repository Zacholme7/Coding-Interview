# Link: https://leetcode.com/problems/permutations/description/
# Difficulty: Medium
# Date solved: Nov 2, 2023
# Solution: 
# This is a very clean solution to this problem and it is very pythonic. The main idea behind this is that we have to keep
# track of what we have visited so far and the "in" keyword makes this quite easy. We want to lop through all permutations,
# so for each iteration we start at the beginning of nums, if we have seen the number already we skip it, else we add it
# and recurse. This will generate all permutations since each time we start a new first pick, we will go back through all 
# of the other numbers starting from the beginning and take each the first time we see it

class Solution:
    def helper(self, tracker,  nums, res):
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
        res = []
        self.helper([], nums, res)
        return res

