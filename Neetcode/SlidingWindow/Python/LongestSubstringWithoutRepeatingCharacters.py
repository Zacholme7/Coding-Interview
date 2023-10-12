# Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Difficulty: Medium
# Date solved: Oct 11, 2023
# Solution
# so this is a relatilvey simple problem. We want to find
# the length of the longest substring without repeating characters.
# we can track what letters are in our curent substring using a set
# and have a left and a right pointer to denote its front and end. If 
# we see a new letter, add it to the set and increase the size, 
# if a letter is already in the set, we need to remove it from the current
# substring since we have reached our max length. We dont know where in the current
# substring this letter is so while the end char is in the set meaning it is in the substring
# we need to remove letters from the start and increment the start so we have a new substring
# with no repeating characters. At the end, we would have removed the current letter which we want
# so we have to add that back in. Then at the end we just return the max length

class Solution:
    def lengthOfLongestSubstring(self, s):
        startIdx = 0
        letterSet = set()
        maxLen = 0

        for endIdx in range(len(s)):
            if s[endIdx] not in letterSet:
                letterSet.add(s[endIdx])
                maxLen = max(endIdx - startIdx + 1, maxLen)
            else:
                while s[endIdx] in letterSet:
                    letterSet.remove(s[startIdx])
                    startIdx += 1
                letterSet.add(s[endIdx])
        return maxLen
