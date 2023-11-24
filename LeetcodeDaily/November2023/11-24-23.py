# Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/?envType=daily-question&envId=2023-11-24
# Difficulty: Medium
# Date Solved: November 24, 2023

class Solution:
    def maxCoins(self, A):
        return sum(sorted(A)[len(A) // 3::2])