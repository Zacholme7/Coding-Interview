# https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/?envType=daily-question&envId=2023-11-30
# Difficulty: Hard
# Date solved: November 30, 2023

class Solution:
    def minimumOneBitOperations(self, n):
        if n == 0:
            return 0

        k = 0
        while 2**k <= n:
            k += 1
        k -= 1
        return 2 ** (k + 1) - 1 - self.minimumOneBitOperations(2 ** k ^ n)

