# link: https://leetcode.com/problems/count-of-matches-in-tournament/?envType=daily-question&envId=2023-12-05
# Difficulty: Easy
# Date solved: December 5, 2023

class Solution:
    def numberOfMatches(self, n):
        # can also just return n - 1... lol
        total = 0
        while n != 1:
            if n % 2 == 0:
                total += n // 2
                n //= 2
            else:
                total += (n - 1) // 2
                n = ((n - 1) // 2)+ 1
        return total
