# link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/solutions/1238655/java-c-python-min-max/?envType=daily-question&envId=2023-11-17
# difficulty: medium
# date solved: November 17, 2023

class Solution:
    def minPairSum(self, nums):
        # min + max and work way inwards
        return max(a + b for a, b in zip(sorted(nums), sorted(nums)[::-1]))