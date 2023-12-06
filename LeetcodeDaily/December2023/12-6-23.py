# https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06
# Difficulty: Easy
# Date Solved: December 6, 2023

class Solution:
    def totalMoney(self, n):
        start = 1
        total = 0
        while n > 0:
            days_this_week = min(n, 7)  # Calculate the number of days in the current week
            end = start + days_this_week - 1
            total += (days_this_week * (start + end)) // 2  # Use integer division
            start += 1  # Increment start for the next week
            n -= days_this_week  # Decrement the number of days remaining
        return total
            
            

