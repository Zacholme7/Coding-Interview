# link: https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25
# difficiulty: medium
# date solved: april 25, 2024

class Solution:
    def longestIdealString(self, s, k):
        l = [0] * 128
        for c in s:
            i = ord(c)
            l[i] = max(l[i - k: i + k + 1]) + 1
        return max(l)
