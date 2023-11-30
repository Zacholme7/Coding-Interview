# Link: https://leetcode.com/problems/number-of-1-bits/?envType=daily-question&envId=2023-11-29
# Difficulty: Easy
# Date Solved: November 29, 2023

class Solution:
    def hammingWeight(self, n: int) -> int:
        counter = 0
        while n:
            n &= n -1
            counter += 1
        return counter


