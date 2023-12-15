# link: https://leetcode.com/problems/destination-city/?envType=daily-question&envId=2023-12-15
# Difficulty: Easy
# Date solved: December 15, 2023

class Solution:
    def destCity(self, paths):
        setA = set()
        setB = set()

        for path in paths:
            pathA, pathB = path
            setA.add(pathA)
            setB.add(pathB)

        for loc in setB:
            if loc not in setA:
                return loc

        return -1



