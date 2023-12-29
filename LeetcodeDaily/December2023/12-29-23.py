# link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/?envType=daily-question&envId=2023-12-29
# difficulty: hard
# date solved: december 29, 2023

class Solution:
    def minDifficulty(self, jobDifficulty, d):
        if len(jobDifficulty) < d:
            return -1

        cache = {}
        def dfs(i, d, cur_max):
            if i == len(jobDifficulty):
                return 0 if d == 0 else float("inf")
            if d == 0:
                return float("inf")

            if (i, d, cur_max) in cache:
                return cache[(i, d, cur_max)]

            cur_max = max(cur_max, jobDifficulty[i])
            res = min(
                dfs(i + 1, d, cur_max), # continue day
                cur_max + dfs(i + 1, d - 1, -1) # end day
            )
            cache[(i, d, cur_max)] = res
            return res


        return dfs(0, d, -1)
