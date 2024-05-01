# link: https://leetcode.com/problems/reverse-prefix-of-word/?envType=daily-question&envId=2024-05-01
# difficulty: easy
# date solved: may 1, 2024

class Solution:
    def reversePrefix(self, word, ch):
        stack = []
        for idx, letter in enumerate(word):
            stack.append(letter)
            if letter == ch:
                reversed = "".join(stack[::-1])
                return reversed + word[idx + 1:]
        return word


if __name__ == "__main__":
    sol = Solution()
    print(sol.reversePrefix("abcdefd", "d"))
    print(sol.reversePrefix("xyxzxe", "z"))
    print(sol.reversePrefix("abc", "z"))
