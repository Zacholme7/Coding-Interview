# link: https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
# difficulty: easy
# date solved: february 5, 2024

from collections import defaultdict


class Solution:
    def firstUniqChar(self, s):
        charMap = defaultdict(int)
        for char in s:
            charMap[char] += 1

        for idx, char in enumerate(s):
            if charMap[char] == 1:
                return idx
        return -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.firstUniqChar("leetcode"))
    print(sol.firstUniqChar("loveleetcode"))
    print(sol.firstUniqChar("aabb"))
