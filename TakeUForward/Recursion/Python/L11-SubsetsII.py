# https://leetcode.com/problems/subsets-ii/description/
# Difficulty:  Medium
# Date Solved: Oct 26, 2023
# Solution:
# This is a different structure of recursion problem that deals when we 
# have duplicates and we want unique elements. The for loop is necessary for this and checking
# if the last element is the one we already started with. The other tricky part is that we need to
# add the tracker righta way and not when it is the length of the list

class Solution:
        def helper(self, idx, tracker, res, nums):
                res.append(tracker.copy())

                for i in range(idx, len(nums)):
                        if i > idx and nums[i] == nums[i-1]:
                                continue
                        tracker.append(nums[i])
                        self.helper(i + 1, tracker, res, nums)
                        tracker.pop(-1)
                        
        def subsetsWithDup(self, nums):
                res = []
                nums = sorted(nums)
                self.helper(0, [], res, nums)
                return res





