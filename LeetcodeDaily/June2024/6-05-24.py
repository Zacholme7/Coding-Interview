# link: https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
# difficulty: easy
# date solved: june 5, 2024

from collections import Counter


class Solution:
    def commonChars(self, words):
        # Initialize with the character count of the first word
        common_count = Counter(words[0])

        # Intersect the counts with the counts from the other words
        for word in words[1:]:
            common_count &= Counter(word)

        # Create the result list based on the common counts
        res = []
        for char, count in common_count.items():
            res.extend([char] * count)

        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.commonChars(["bella", "label", "roller"]))
    print(sol.commonChars(["cool", "lock", "cook"]))
