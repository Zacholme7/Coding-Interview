# link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=daily-question&envId=2023-12-21
# difficulty: medium
# date solved: December 21, 2023

class Solution:
    def maxWidthOfVerticalArea(self, points):
        points.sort()
        return max(points[i][0] - points[i - 1][0] for i in range(1, len(points))
