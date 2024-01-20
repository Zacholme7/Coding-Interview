# link: https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20
# difficulty: medium
# date solved: january 20, 2024


class Solution:

    def sumSubarrayMins(self, arr):
        MOD = 10 ** 9 + 7
        res = 0
        arr = [float("-inf")] + arr + [float("-inf")]
        stack = []

        for i, n in enumerate(arr):
            while stack and n < stack[-1][1]:
                j, m = stack.pop()
                left = j - stack[-1][0] if stack else j + 1
                right = i - j
                res = (res + m * left * right) % MOD

            stack.append((i, n))
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.sumSubarrayMins([3, 1, 2, 4]))
