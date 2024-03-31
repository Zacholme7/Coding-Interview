# link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2024-03-31
# difficulty: hard
# date solved: march 31, 2024

class Solution:
    def countSubarrays(self, nums, mink, maxK):
        res = 0
        bad_idx = left_idx = right_idx = -1

        for i, num in enumerate(nums):
            if not mink <= num <= maxK:
                bad_idx = i

            if num == mink:
                left_idx = i

            if num == maxK:
                right_idx = i

            res += max(0, min(left_idx, right_idx) - bad_idx)

        return res
