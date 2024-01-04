# link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-04
# difficulty: medium
# date solved: january 4, 2023

class Solution:
    def minOperations(self, nums):
        count = Counter(nums)
        res = 0
        for n, c in count.items():
            if c == 1:
                return -1
            res += math.ceil(c / 3)

        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.minOperations([2, 3, 3, 2, 2, 4, 2, 3, 4]))
    print(sol.minOperations([2, 1, 2, 2, 3, 3]))



