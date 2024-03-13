# link: https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13
# difficulty: easy
# date solved: march 13, 2024

class Solution:
    def pivotInteger(self, n: int) -> int:
        total_sum = n * (n + 1) // 2
        left_sum = 0

        for i in range(1, n + 1):
            # Subtract the current number to get the sum of the right part
            right_sum = total_sum - left_sum - i

            if left_sum == right_sum:
                return i

            left_sum += i

        return -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.pivotInteger(8))
    print(sol.pivotInteger(1))
    print(sol.pivotInteger(4))
