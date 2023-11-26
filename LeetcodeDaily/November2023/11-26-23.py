# Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26
# Difficulty: Medium
# Date Solved: November 26, 2023

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n, ans = len(matrix), len(matrix[0]), 0

        for j in range(n):
            for i in range(1, m):
                matrix[i][j] += matrix[i-1][j] if matrix[i][j] else 0

        for i in range(m):
            matrix[i].sort(reverse=1)
            for j in range(n):
                ans = max(ans, (j+1)*matrix[i][j])
        return ans
