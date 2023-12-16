# link: https://leetcode.com/problems/valid-anagram/submissions/?envType=daily-question&envId=2023-12-16
# difficulty: easy
# date solved: December 16, 2023

from collections import defaultdict
class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t): return False # if they are not the same length, then they cannot be anagrms

        letterDict = defaultdict(lambda : 0) # dictionary to keep track of letter counts

        # loop through each word
        for i in range(len(s)):
            letterDict[s[i]] += 1
            letterDict[t[i]] -= 1

        # loop through dict, if any count is not zero then we know it is not an anagram
        for value in letterDict.values():
            if value != 0: return False

        return True

