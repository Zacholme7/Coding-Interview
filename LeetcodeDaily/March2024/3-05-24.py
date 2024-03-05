# link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
# difficulty: medium
# date solved: March 5, 2024

class Solution:
    def minimumLength(self, s):
        left, right = 0, len(s) - 1

        while left < right and s[left] == s[right]:
            common_char = s[left]
            while left <= right and s[left] == common_char:
                left += 1
            while right >= left and s[right] == common_char:
                right -= 1

        return max(0, right - left + 1)


if __name__ == "__main__":
    sol = Solution()
    print(sol.minimumLength("ca"))
    print(sol.minimumLength("cabaabac"))
    print(sol.minimumLength("aabccabba"))
