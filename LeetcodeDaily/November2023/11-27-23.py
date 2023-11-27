# Link: https://leetcode.com/problems/knight-dialer/solutions/189252/o-logn/?envType=daily-question&envId=2023-11-27
# Difficulty: Medium
# Date solved: November 27, 2023

class Solution:
    def knightDialer(self, N):
        x1 = x2 = x3 = x4 = x5 = x6 = x7 = x8 = x9 = x0 = 1
        for i in range(N - 1):
            x1, x2, x3, x4, x5, x6, x7, x8, x9, x0 = \
                x6 + x8, x7 + x9, x4 + x8, \
                x3 + x9 + x0, 0, x1 + x7 + x0, \
                x2 + x6, x1 + x3, x2 + x4, \
                x4 + x6
        return (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x0) % (10**9 + 7)
