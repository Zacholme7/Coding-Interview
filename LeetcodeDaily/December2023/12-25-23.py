# link: https://leetcode.com/problems/decode-ways/?envType=daily-question&envId=2023-12-25
# difficulty: medium
# date solved: december 25, 2023

class Solution:
    def helper(self, ptr, s, memo):
        if ptr in memo:
            return memo[ptr]

        # Base case: if pointer reaches the end of the string
        if ptr == len(s):
            return 1

        # If the current digit is '0', it can't be decoded
        if s[ptr] == '0':
            return 0

        # Single digit decode
        count = self.helper(ptr + 1, s, memo)

        # Double digit decode
        if ptr < len(s) - 1 and 10 <= int(s[ptr:ptr + 2]) <= 26:
            count += self.helper(ptr + 2, s, memo)

        memo[ptr] = count
        return count

    def numDecodings(self, s):
        memo = {}
        return self.helper(0, s, memo)


if __name__ == "__main__":
    sol = Solution()
    print(sol.numDecodings("12"))
    print(sol.numDecodings("226"))
    print(sol.numDecodings("06"))


