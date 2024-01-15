# link: https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=daily-question&envId=2024-01-14
# difficulty: medium
# date solved: january 14, 2024


class Solution:
    def closeStrings(self, word1, word2):

        if set(word1) != set(word2):
            return False

        word1Cnt = {char: word1.count(char) for char in set(word1)}
        word2Cnt = {char: word2.count(char) for char in set(word2)}

        return sorted(word1Cnt.values()) == sorted(word2Cnt.values())


if __name__ == "__main__":
    sol = Solution()

    print(sol.closeStrings("abc", "bca"))
    print(sol.closeStrings("a", "aa"))
    print(sol.closeStrings("cabbba", "abbccc"))
    print(sol.closeStrings("cabbba", "aabbss"))
