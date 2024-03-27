# link: https://leetcode.com/problems/subarray-product-less-than-k/solutions/?envType=daily-question&envId=2024-03-27
# difficulty: medium
# date solved: march 27, 2024

class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        if k <= 1:
            return 0

        left, right, product, count = 0, 0, 1, 0
        n = len(nums)

        while right < n:
            product *= nums[right]
            while product >= k:
                product //= nums[left]
                left += 1
            count += 1 + (right - left)
            right += 1

        return count
