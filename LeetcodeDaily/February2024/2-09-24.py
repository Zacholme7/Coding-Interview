# link: https://leetcode.com/problems/largest-divisible-subset/?envType=daily-question&envId=2024-02-09
# difficulty: medium
# date solved: february 9, 2024

class Solution:
    def largestDivisibleSubset(self, nums):
        if len(nums) == 0:
            return []
        nums.sort()
        sol = [[num] for num in nums]
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and len(sol[i]) < len(sol[j]) + 1:
                    sol[i] = sol[j] + [nums[i]]
        return max(sol, key=len)
