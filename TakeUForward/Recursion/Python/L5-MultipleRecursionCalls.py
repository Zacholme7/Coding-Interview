# https://www.youtube.com/watch?v=kvRjNm4rVBE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=5
# Date: Oct 24, 2023
# This lecture teaches multiple recursion calls using the fibonnaci sequence
# Time complexity: 2 power n, exponential
# Space complexity: 2 power n, exponential

class Solution:
    def calculate_fib(self, n):
        if n <= 1:
            return n
        return self.calculate_fib(n - 1) + self.calculate_fib(n - 2)

if __name__ == '__main__':
    sol = Solution()
    print(str(sol.calculate_fib(1)) + " should be 1")
    print(str(sol.calculate_fib(4)) + " should be 3")

