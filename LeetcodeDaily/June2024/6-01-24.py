# Link: https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01
# difficulty: easy
# date solved: june 1, 2024

class Solution:
    def scoreOfString(self, s):
        score = 0
        for i in range(1, len(s)):
            score += abs(ord(s[i - 1]) - ord(s[i]))
        return score
