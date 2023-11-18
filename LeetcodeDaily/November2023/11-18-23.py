# Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/?envType=daily-question&envId=2023-11-18
# Difficulty: Medium
# Date solved: November 18, 2023

class Solution:
    def maxFrequency(self, A, k):
        i = 0
        A.sort()
        for j in range(len(A)):
            k += A[j]
            if k < A[j] * (j - i + 1):
                k -= A[i]
                i += 1
        return j - i + 1