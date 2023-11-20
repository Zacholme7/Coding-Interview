# Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/?envType=daily-question&envId=2023-11-20
# Difficulty: Medium
# Date Solved: November 20, 2023

class Solution:
    def garbageCollection(self, garbage, travel):
        total = 0
        n = len(garbage)

        for c in "MPG":
            mx = 0
            current = 0

            current += garbage[0].count(c)
            mx = max(current, mx)

            for i in range(1, n):
                current += travel[i - 1]
                if c in garbage[i]:
                    current += garbage[i].count(c)
                    mx = max(current, mx)
            total += mx

        return total


        


