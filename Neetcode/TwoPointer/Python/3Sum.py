# Link: https://leetcode.com/problems/3sum/submissions/722473892/
# Difficulty: Medium
# Date solved: Oct 10, 2023
# Solution
# this is the trickiest of the sum problems yet. In this one,
# we want to find the three numbers that add up to zero which is 
# not that hard but we want to make sure there is no duplicates.
# We will have a pointer i as our base number and have a sliding
# window at i + 1 and len(nums) - 1. We can then move the left and
# the right points of the window based on the total relative to zero
# since we sorted the array to start off with. The tricky part is that
# when we find one solution, we dont want it again, so we have to skip
# the following numbers that are the same. This is done in the two while
# loops right after we add a solution

class Solution:
    def threeSum(self, nums):
        nums.sort()
        res = []
        for i in range(len(nums) - 2):
            if i != 0 and nums[i-1] == nums[i]:
                continue
            else:
                left = i + 1
                right = len(nums) - 1
                while left < right:
                    currTotal = nums[left] + nums[right] + nums[idx]
                    if currTotal == 0:
                        res.append([nums[idx], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < len(nums) and nums[left - 1] == nums[left]:
                            left += 1
                        while right > 0 and nums[right + 1] == nums[right]:
                            right -= 1
                    elif currTotal < 0:
                        left +=1
                    else:
                        right -= 1
        return res





