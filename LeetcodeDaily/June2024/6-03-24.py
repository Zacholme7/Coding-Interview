# link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03
# difficulty: medium
# date solved: june 3, 2024

class Solution:
    def appendCharacters(self, s, t):
        ptr = 0
        for letter in s:
            if ptr >= len(t):
                return 0
            if letter == t[ptr]:
                ptr += 1

        return len(t[ptr:])


if __name__ == "__main__":
    sol = Solution()
    print(sol.appendCharacters("coaching", "coding"))
    print(sol.appendCharacters("abcde", "a"))
    print(sol.appendCharacters("z", "abcde"))
