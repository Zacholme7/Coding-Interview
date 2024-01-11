# rlink: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02
# difficulty: medium
# date solved: january 2, 2023

from collections import defaultdict


class Solution:
    def findMatrix(self, nums):
        numCnt = defaultdict(int)
        res = []

        for n in nums:
            row = numCnt[n]
            if len(res) == row:
                res.append([])

            res[row].append(n)
            numCnt[n] += 1

        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.findMatrix([1, 3, 4, 1, 2, 3, 1]))
    print(sol.findMatrix([1, 2, 3, 4]))
