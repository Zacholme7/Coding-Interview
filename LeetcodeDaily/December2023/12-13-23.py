# Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2023-12-13
# Difficulty: Easy
# Date Solved: December 13, 2023

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        count = 0
        pivot = list(zip(*mat))
        for row in mat:
            if sum(row) == 1:
                j = row.index(1)
                if sum(pivot[j]) == 1:
                    count += 1
        return count
