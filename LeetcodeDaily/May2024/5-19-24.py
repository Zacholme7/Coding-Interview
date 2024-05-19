# link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2024-05-19
# difficulty: hard
# date solved: may 19, 2024

class Solution:
    def maximumValueSum(self, nums, k, edges):
        total = sum(nums)

        total_diff = 0
        positive_count = 0
        min_abs_diff = float('inf')

        for num in nums:
            diff = (num ^ k) - num

            if diff > 0:
                total_diff += diff
                positive_count += 1
            min_abs_diff = min(min_abs_diff, abs(diff))

        if positive_count % 2 == 1:
            total_diff -= min_abs_diff

        return total + total_diff
