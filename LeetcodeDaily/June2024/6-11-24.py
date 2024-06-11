# link: https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
# difficulty: easy
# date solved: june 11, 2024

from colletions import defaultdict


class Solution:
    def relativeSortArray(self, arr1, arr2):
        numCnt = defaultdict(int)

        # count all of the elements in arr1
        for num in arr1:
            numCnt[num] += 1

        res = []
        # for each distinct number in arr2, add it * number of times it appears
        # delete it so we have remaining at end
        for num in arr2:
            res += numCnt[num] * [num]
            del numCnt[num]

        for num in sorted(numCnt):
            res += numCnt[num] * [num]

        return res
