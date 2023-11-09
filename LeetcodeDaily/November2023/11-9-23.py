# link: https://leetcode.com/problems/count-number-of-homogenous-substrings/?envType=daily-question&envId=2023-11-09
# Difficulty: Medium
# Date solved: November 9, 2023

class Solution:
    def countHomogenous(self, s):
        MOD = 10**9 + 7
        total = 1  # Starts at 1 because a single character is a homogenous substring
        count = 1  # Counts the length of the current homogenous substring
        
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                count += 1  # Increment the count if the current character is the same as the previous one
            else:
                count = 1  # Reset count if we encounter a different character

            total = (total + count) % MOD  # Add the count to total and use modulo to avoid large numbers

        return total

