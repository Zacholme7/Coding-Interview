# Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2023-11-14
# Difficulty: Medium
# Date Solved: November 14, 2023

import collections
class Solution:
    def countPalindromicSubsequence(self, s):
        res = set()
        left = set()
        right = collections.Counter(s)

        for i in range(len(s)):  # Start loop from 0
            right[s[i]] -= 1
            if right[s[i]] == 0:
                right.pop(s[i])
            
            for j in range(26):
                c = chr(ord('a') + j)
                if c in left and c in right:
                    res.add((c, s[i], c))  # Add a tuple of form (c, s[i], c)

            left.add(s[i])
        return len(res)






