# Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/?envType=daily-question&envId=2023-12-11
# Difficulty: Easy
# Date Solved: December 11, 2023

class Solution:
    def findSpecialInteger(self, arr):
        arrLen = len(arr)
        t = arrLen // 4

        for idx in range(0, arrLen - t):
            if arr[idx] == arr[idx + t]:
                return arr[idx]

        return -1
