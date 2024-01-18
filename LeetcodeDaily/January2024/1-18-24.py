# link: https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18
# difficulty: easy
# date solved: january 18, 2024

class Solution:
    def climbStairs(self, n):
        ans = [1, 1]
        for idx in range(2, n + 1):
            ans.append(ans[idx - 1] + ans[idx - 2])
        return ans[n]
