# Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/?envType=daily-question&envId=2023-12-04
# Difficulty: Easy
# Date Solved: December 4, 2023

class Solution:
    def largestGoodInteger(self, num):
        for i in range(9, -1, -1):
            if str(i) * 3 in num:
                return str(i) * 3
        return ""
