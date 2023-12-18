# link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/?envType=daily-question&envId=2023-12-18
# difficulty: easy
# date solved: december 18, 2023

class Solution:
    def maxProductDifference(self, nums):
        nums.sort()
        return (nums[-2] * nums[-1]) - (nums[0] * nums[1])


