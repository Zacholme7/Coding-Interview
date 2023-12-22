# link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2023-12-22
# difficulty: easy
# date solved: december 22, 2023

class Solution:
    def maxScore(self, s):
        max_score = count_zeros_left = 0
        count_ones_right = s.count('1')

        for i in range(len(s) - 1):
            count_zeros_left += s[i] == '0'
            count_ones_right -= s[i] == '1'
            max_score = max(max_score, count_zeros_left + count_ones_right)

        return max_score
