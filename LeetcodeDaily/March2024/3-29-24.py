# link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29
# difficulty: medium
# date solved: march 29, 2024

class Solution:
    def countSubarrays(self, nums, k):
        mx, ans, l, r, n = max(nums), 0, 0, 0, len(nums)
        while r < n:
            k -= nums[r] == mx
            r += 1
            while k == 0:
                k += nums[l] == mx
                l += 1
            ans += l
        return ans
