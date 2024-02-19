# link: https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19
# difficulty: easy
# date solved: february 19, 2024

class Solution:
    def isPowerOfTwo(self, n):
        while n > 1 and n % 2 == 0:
            n //= 2

        if n == 1:
            return True
        else:
            return False


if __name__ == "__main__":
    sol = Solution()
    print(sol.isPowerOfTwo(1))
    print(sol.isPowerOfTwo(16))
    print(sol.isPowerOfTwo(3))
