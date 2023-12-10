# Link: https://leetcode.com/problems/transpose-matrix/?envType=daily-question&envId=2023-12-10
# Difficulty: Easy
# Date Solved: December 10, 2023

class Solution:
    def transpose(self, A):
        return [[A[i][j] for i in range(len(A))] for j in range(len(A[0]))]
     
