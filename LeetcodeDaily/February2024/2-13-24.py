# link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13
# difficulty: easy
# date solved: february 13, 2024

class Solution:
    def firstPalindrome(self, words):
        for word in words:
            if word == word[::-1]:
                return word
        return ""


if __name__ == "__main__":
    sol = Solution()
    print(sol.firstPalindrome(["abc", "car", "ada", "racecar", "cool"]))
    print(sol.firstPalindrome(["notapalindrome", "racecar"]))
    print(sol.firstPalindrome(["def", "ghi"]))
