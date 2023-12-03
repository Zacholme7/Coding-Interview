# link: https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2023-12-03
# difficulty: Easy
# Date solved: December 3, 2023

class Solution:
    def minTimeToVisitAllPoints(self, points):
        res = 0
        x1, y1 = points.pop()
        while points:
            x2, y2 = points.pop()
            res += max(abs(y2 - y1), abs(x2-x1))
            x1, y1 = x2, y2
        return res








