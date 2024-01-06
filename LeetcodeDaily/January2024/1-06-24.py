# link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/?envType=daily-question&envId=2024-01-06
# difficulty: hard
# date solved: january 6, 2024

class Solution:
    def jobScheduling(self, startTime, endTime, profit):
        intervals = sorted(zip(startTime, endTime, profit))

        cache = {}

        def dfs(i):
            if i == len(intervals):
                return 0

            if i in cache:
                return cache[i]

            # dont include
            res = dfs(i + 1)

            # include 
            j = bisect.bisect(intervals, (intervals[i][1], -1))
            cache[i] = res = max(res, intervals[i][2]+ dfs(j))
            return res

        return dfs(0)




