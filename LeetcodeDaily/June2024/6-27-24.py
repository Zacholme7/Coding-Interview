# link: https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27
# difficulty: easy
# date solved: june 27, 2024

class Solution:
    def findCenter(self, edges):
        return edges[0][0] if edges[0][0] in edges[1] else edges[0][1]
