# Video: https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6
# Date: May 9, 2023
# This video talks about going through all subsequences which is a huge part of recursive problems
# Time complexity: 2 power n * n
# Space complexity: n
# Explanation:
# this is a baisc for to print all of the subsequences of an array.
# for each recursive call, we choose to pick or not pick. On the first 
# time we see a number, we choose to pick it. We then increment out index and
# repreat the same process for the next number. Eventually, when we hit the base case
# we will return and pop the number off, simulating that we are not picking it and move onto the next 
# iteration

class Solution:
    def print_subsequences(self, n , vec, numbers):
        if n >= len(numbers):
            print(vec)
            return

        vec.append(numbers[n])
        self.print_subsequences(n + 1, vec, numbers)
        vec.pop(-1)
        self.print_subsequences(n + 1, vec, numbers)

if __name__ == '__main__':
    sol = Solution()
    numbers = [3, 1, 2]
    vec = []
    sol.print_subsequences(0, vec, numbers)

