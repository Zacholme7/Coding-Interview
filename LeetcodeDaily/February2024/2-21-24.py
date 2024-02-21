# link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21
# difficulty: medium
# date solved: february 21, 2024

class Solution:
    def rangeBitwiseAnd(self, left, right):
        cnt = 0
        while left != right:
            left >>= 1
            right >>= 1
            cnt += 1
        return left << cnt


if __name__ == "__main__":
    sol = Solution()
    print(sol.rangeBitwiseAnd(5, 7))
    print(sol.rangeBitwiseAnd(0, 0))
    print(sol.rangeBitwiseAnd(0, 2147483647))
