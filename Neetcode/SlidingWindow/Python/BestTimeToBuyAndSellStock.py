# Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Difficulty: Easy
# Date solved: Oct 10, 2023
# Solution
# this is a simple problme, we just want to keep track
# of what day we can buy at the lowest and calculate what the potential
# profit each day is off of the lowest buy prices we have seen so far and what
# the current sell price is

class Solution:
    def maxProfit(self, prices):
        buyIdx = 0
        currProfit = 0
        for idx in range(1, len(prices)):
            currProfit = max(currProfit, prices[idx] - prices[buyIdx])
            if prices[idx] < prices[buyIdx]:
                buyIdx = idx
        return currProfit



