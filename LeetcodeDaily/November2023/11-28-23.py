# https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/?envType=daily-question&envId=2023-11-28
# Difficulty: Hard
# Date Solved: November 28, 2023

class Solution:
    def numberOfWays(self, s):
        a = [i for i,c in enumerate(s) if c == 'S']
        res = 1
        for i in range(1,len(a) - 1,2):
            res *= a[i+1] - a[i]
        return res % (10**9+7) * (len(a) % 2 == 0 and len(a) >= 2)
