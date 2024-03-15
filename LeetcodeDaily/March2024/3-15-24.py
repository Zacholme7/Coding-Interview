# link: https://leetcode.com/problems/product-of-array-except-self/?envType=daily-question&envId=2024-03-15
# difficulty: medium
# date solved: march 15, 2024

class Solution:
    def productExceptSelf(self, nums):
        outArr = [1] * len(nums)
        for idx in range(1, len(nums)):
            outArr[idx] = outArr[idx - 1] * nums[idx - 1]
        for idx in range(len(nums) - 2, -1, -1):
            outArr[idx] = outArr[idx] * nums[idx + 1]
            nums[idx] = nums[idx] * nums[idx + 1]
        return outArr
