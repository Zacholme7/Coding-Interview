# https://leetcode.com/problems/combination-sum-ii/description/
# Difficulty: Medium
# Date Solved: October 25, 2023
# Solution:
# this is a twist on combination sum one.
# One thing here is that we cannot ahve duplicate solutions
# for our base cases if the current sum is less than zero we want to return
# since we dont ahve negative nubmers and if the current sum is zero then we have
# a solution. On each start of the new loop, we check to make sure that the previous number
# is not the same as the one that we are at now. this is to ensure that we do not add in duplicates

class Solution:
    
    def helper(self, idx, curr_sum, tracker, res, candidates):
        if curr_sum < 0:
            return 
        if curr_sum == 0:
            res.append(tracker.copy())
        for i in range(idx, len(candidates)):
            if i > idx and candidates[i] == candidates[i - 1]:
                continue
            self.helper(i + 1, curr_sum - candidates[i], tracker + [candidates[i]], res, candidates)


    def combinationSum2(self, candidates, target):
        res = []
        candidates = sorted(candidates)
        self.helper(0, target, [], res, candidates)
        return res
