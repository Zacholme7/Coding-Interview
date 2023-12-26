# link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/?envType=daily-question&envId=2023-12-26
# difficulty: medium
# date solved: december 26, 2023

class Solution:
    def numRollsToTarget(self, n, k, target):
        # for the number of dices
        dp = [0] * (target + 1) # the number of ways to roll the value i
        dp[0] = 1
        MOD = 10**9 + 7

        for dice in range(n):
            next_dp = [0] * (target + 1)
            for val in range(1, k+1):
                for toatl in range(val, target + 1):
                    next_dp[total] = (next_dp[total] + dp[total - val]) % MOD
            dp = next_dp
        return dp[target]


