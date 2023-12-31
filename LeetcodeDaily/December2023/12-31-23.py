# link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
# difficulty: easy
# date solved: december 31, 2023

class Solution:
    def maxLengthBetweenEqualCharacters(self, s):
        last_occurrence = {}
        max_length = -1

        for i, char in enumerate(s):
            if char in last_occurrence:
                max_length = max(max_length, i - last_occurrence[char] - 1)
            else:
                last_occurrence[char] = i

        return max_length

    
