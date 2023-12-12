# link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2023-12-12
# difficulty: easy
# date solved: december 12, 2023

class Solution:
    def maxProduct(self, nums):
        nums.sort()

        return (nums[-1] - 1)  * (nums[-2] - 1)
