# Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/?envType=daily-question&envId=2023-12-02
# Difficulty: Easy
# Date solved: December 2, 2023

from collections import defaultdict
class Solution:
    def countCharacters(self, words, chars):
        charDict = defaultdict(int)
        totalLength = 0

        for c in chars:
            charDict[c] += 1

        for word in words:
            res = self.canForm(word, charDict.copy())
            if res:
                totalLength += len(word)
        return totalLength

    def canForm(self, word, charDict):
        for c in word:
            charDict[c] -= 1
            if charDict[c] < 0:
                return False
        return True


