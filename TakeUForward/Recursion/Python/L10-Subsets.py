# Link: https://leetcode.com/problems/subsets/
# Difficulty:  Medium
# Date Solved: Oct 26, 2023
# Solution:
# This is about as basic of a recursion problem as you can get and it has many modifications to address
# other problems, but this can be thought of as the blueprint. This is just taking all of the subsets. When our
# idx is the len of the list, that is our basecase and we want to add the subset. Otherwise, it is just a classic pick and not 
# pick structure

class Solution:
        def helper(self, idx, n, nums, tracker, res):
                if idx == n:
                        res.append(tracker.copy())
                        return
                tracker.append(nums[idx])
                self.helper(idx + 1, n, nums, tracker.append(nums[idx]), res)
                tracker.pop(-1)
                self.helper(idx + 1, n, nums, tracker, res)
        

        def subsets(self, nums):
                res = []
                self.helper(0, len(nums), nums, [], res)
                return res
    