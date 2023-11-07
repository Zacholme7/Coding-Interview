# Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-11-07
# Difficulty: Medium
# Date Solved: November 7, 2023

class Solution:
    def eliminateMaximum(self, dist, speed):
        time_to_city = [dist[i] / speed[i] for i in range(len(dist))]
        time_to_city.sort()

        for i in range(len(time_to_city)):
            if time_to_city[i] <= i:
                return i
            
        return len(dist)

