# link: https://leetcode.com/problems/partition-array-for-maximum-sum/?envType=daily-question&envId=2024-02-03
# difficulty: medium
# date solved: february 3, 2024

class Solution:
    def maxSumAfterPartitioning(self, A, K):
        N = len(A)
        dp = [0] * (N + 1)
        for i in range(1, N + 1):
            curMax = 0
            for k in range(1, min(K, i) + 1):
                curMax = max(curMax, A[i - k])
                dp[i] = max(dp[i], dp[i - k] + curMax * k)
        return dp[N]
