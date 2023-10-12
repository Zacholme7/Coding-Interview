# Link: https://leetcode.com/problems/valid-anagram/
# Difficulty: Easy
# Date solved: Sept 10, 2023
# Solution:
# We are checking if the words are anagrams, that means that there will be the 
# same amount of each letter in each word if they are anagrams. Due to this,
# we can keep a positive count of the number of each letter in one word, while
# decrementing this count by the number of letters in the other word. We can
# then loop through the tracking method, which in this case is a defaultdict,
# and if any of the values are not zero, this means that one of the words had
# an excess of a certain char and the two strings are not anagrms. Otherwise,
# they are

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

