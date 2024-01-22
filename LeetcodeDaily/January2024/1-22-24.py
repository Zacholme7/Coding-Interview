# link: https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
# difficulty: easy
# date solved: january 22, 2023
# T(n)
# C(n)

class Solution:
    def findErrorNums(self, nums):
        res = [0, 0]
        count = [0] * (len(nums) + 1)
        for num in nums:
            count[num] += 1
        for idx in range(1, len(nums) + 1):
            if count[idx] == 2:
                res[0] = idx
            if count[idx] == 0:
                res[1] = idx
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.findErrorNums([1, 2, 2, 4]))
    print(sol.findErrorNums([1, 1]))
    print(sol.findErrorNums([2, 2]))
