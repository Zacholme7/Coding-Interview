# leetcoding on my birthday huh ;)
# link: https://leetcode.com/problems/diagonal-traverse-ii/?envType=daily-question&envId=2023-11-22
# Difficulty: Medium
# Date solved: November 22, 2023

from collections import defaultdict
class Solution:
    def findDiagonalOrder(self, A):
        res = []
        for i, r in enumerate(A):
            for j, a in enumerate(r):
                if len(res) <= i + j:
                    res.append([])
                res[i + j].append(a)
        return [a for r in res for a in reversed(r)]




        
        





