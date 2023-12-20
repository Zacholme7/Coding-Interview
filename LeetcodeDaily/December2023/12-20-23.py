# link: https://leetcode.com/problems/buy-two-chocolates/?envType=daily-question&envId=2023-12-20
# difficulty: easy
# date solved: december 20, 2023

class Solution:
    def buyChoco(self, prices, money):
        prices.sort()
        sum = prices[0] + prices[1]
        return money if sum > money else money - sum

