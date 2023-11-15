# link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/solutions/?envType=daily-question&envId=2023-11-15
# difficulty: Medium
# Date solved: November 15, 202.

class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        arr.sort()
        pre = 0
        for ele in arr:
            pre = min(pre + 1, ele)
        return pre

