# Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/?envType=daily-question&envId=2023-12-01
# Difficulty: Easy
# Date Solved: December 1, 2023

class Solution:
    def arrayStringsAreEqual(self, word1, word2):
        return "".join(word1) == "".join(word2)
