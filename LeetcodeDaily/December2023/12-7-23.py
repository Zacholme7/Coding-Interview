# link: https://leetcode.com/problems/largest-odd-number-in-string/?envType=daily-question&envId=2023-12-07
# Difficulty: Easy
# Date Solved: December 7, 2023

class Solution:
    def largestOddNumber(self, num):
        # we know least signfiicant number will indicate if it is odd
        for idx in range(len(num) - 1, -1, -1):
            currNum = int(num[idx])
            if currNum % 2 != 0:
                return num[0:idx+1]
        return ""  






