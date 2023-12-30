# link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/?envType=daily-question&envId=2023-12-30
# difficulty: easy
# date solved: december 30, 2023

from collections import defaultdict
class Solution:
    def makeEqual(self, words):
        letterCnt = defaultdict(lambda : 0)
        for word in words:
            for letter in word:
                letterCnt[letter] += 1

        wordsLen = len(words)
        for value in letterCnt.values():
            if value % wordsLen != 0:
                return False

        return True


if __name__ == "__main__":
    sol = Solution()
    print(sol.makeEqual(["abc", "aabc", "bc"]))
    print(sol.makeEqual(["ab", "a"]))
