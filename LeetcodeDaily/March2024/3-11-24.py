# link: https://leetcode.com/problems/custom-sort-string/?envType=daily-question&envId=2024-03-11
# difficulty: medium
# date solved: march 11, 2024
from collections import defaultdict


class Solution:
    def customSortString(self, order, s):
        result = ""
        mp = defaultdict(int)

        for char in s:
            mp[char] += 1

        for char in order:
            if char in mp:
                result += char * mp[char]
                del mp[char]

        for char, count in mp.items():
            result += char * count
        return result


if __name__ == "__main__":
    sol = Solution()
    print(sol.customSortString(order="cba", s="abcd"))
    print(sol.customSortString(order="bcafg", s="abcd"))
    print(sol.customSortString(order="kqep", s="pekeq"))
