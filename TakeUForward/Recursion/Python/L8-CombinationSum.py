# Link: https://leetcode.com/problems/combination-sum/
# Difficulty: Medium
# Date solved: Oct 24, 2023
# Solution: 
# this is a recursive solution with a mix on a subset problem.
# The key here is that we can repeat numbers
# so our base case is the usual when the idx is the length of the array
# our recursive case is that if we can still add the number and be less than or equal to the
# target, we want to take that number and put it onto our tracker but we do not want to increment
# our index, this means that we can pick this number again. If we exceed the target, that is when we want to take it off




class Solution:

    def combination_sum_helper(self, idx, curr_sum, res, tracker, candidates):
        if idx == len(candidates):
            if curr_sum == 0:
                res.append(tracker.copy())
            return

        if candidates[idx] <= curr_sum:
            tracker.append(candidates[idx])
            self.combination_sum_helper(idx, curr_sum - candidates[idx], res, tracker, candidates)
            tracker.pop(-1)

        self.combination_sum_helper(idx + 1, curr_sum, res, tracker, candidates)
        




    def combination_sum(self, candidates, target):
        res = []
        tracker = []
        self.combination_sum_helper(0, target, res, tracker, candidates)
        return res

