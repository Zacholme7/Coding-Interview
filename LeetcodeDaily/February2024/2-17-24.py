# link: https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17
# difficulty: medium
# date solved: february 17, 2024
import heappush
import heappop


class Solution:
    def furthestBuilding(self, heights, bricks, ladders):
        pq = []
        for i in range(len(heights) - 1):
            diff = heights[i + 1] - heights[i]
            if diff <= 0:
                continue
            heappush(pq, diff)
            if len(pq) > ladders:
                bricks -= heappop(pq)
            if bricks < 0:
                return i
        return len(heights) - 1
