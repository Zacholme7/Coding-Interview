# link: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
# difficulty: easy
# date solved: july 7, 2024

class Solution:
        def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
                ans = numBottles
                while numBottles >= numExchange:
                        numBottles, remainder = divmod(numBottles, numExchange)
                        ans += numBottles
                        numBottles += remainder
                return ans