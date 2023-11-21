# link: https://leetcode.com/problems/count-nice-pairs-in-an-array/?envType=daily-question&envId=2023-11-21
# Difficulty: Medium
# Date solved: November 21, 2023

class Solution:
    def countNicePairs(self, nums):
        res = 0
        count = collections.Counter()
        for a in nums:
            b = int(str(a)[::-1])
            res += count[a - b]
            count[a - b] += 1
        return res % (10**9 + 7)
