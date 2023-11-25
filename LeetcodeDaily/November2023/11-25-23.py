# Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=daily-question&envId=2023-11-25
# Difficulty: Medium
# Date Solved: November 25, 2023

class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n, prefix_sum, res = len(nums), [0], []
        for num in nums:
            prefix_sum += [num + prefix_sum[-1]]
        for i, num in enumerate(nums):
            res += [i * num - prefix_sum[i] + prefix_sum[n] - prefix_sum[i] - (n - i) * num]    
        return res

