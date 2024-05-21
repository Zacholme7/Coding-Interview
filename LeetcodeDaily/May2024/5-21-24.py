# link: https://leetcode.com/problems/subsets/?envType=daily-question&envId=2024-05-21
# difficulty: medium
# date solved: may 21st 2024


class Solution:
    def subsets(self, nums):
        res = []

        def helper(idx, tracker):
            nonlocal res
            if idx == len(nums):
                res.append(tracker[:])
                return

            tracker.append(nums[idx])
            helper(idx + 1, tracker)
            tracker.pop()
            helper(idx + 1, tracker)

        helper(0, [])
        return res
