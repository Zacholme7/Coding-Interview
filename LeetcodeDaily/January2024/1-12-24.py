# link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12
# difficulty: easy
# date solved: january 12, 2024


class Solution:
    def halvesAreAlike(self, s):
        a, b = s[:len(s) // 2], s[len(s) // 2:]
        letters = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

        aCnt, bCnt = 0, 0
        for idx in range(len(a)):
            if a[idx] in letters:
                aCnt += 1
            if b[idx] in letters:
                bCnt += 1

        return aCnt == bCnt


if __name__ == "__main__":
    sol = Solution()
    print(sol.halvesAreAlike("book"))
    print(sol.halvesAreAlike("textbook"))
