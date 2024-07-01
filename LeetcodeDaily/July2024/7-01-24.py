# link: https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2024-07-01
# difficulty: easy
# date solved: july 1, 2024


class Solution:
    def threeConsecutiveOdds(self, arr):
        numConsecutive = 0
        for num in arr:
            if num % 2 == 1: 
                numConsecutive += 1
                if numConsecutive == 3:
                    return True
            else: 
                numConsecutive = 0
        return False
