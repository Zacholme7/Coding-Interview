# link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
# difficulty: easy
# date solved: janauary 23, 2024

class Solution:
    def check(self, nums):
        numLen = len(nums)
        counter = 0
        for idx in range(0, len(nums)):
            if nums[idx] > nums[(idx + 1) % numLen]:
                counter += 1

        if counter <= 1:
            return True
        return False


if __name__ == "__main__":
    sol = Solution()
    print(sol.check([3, 4, 5, 1, 2]))
    print(sol.check([2, 1, 3, 4]))
    print(sol.check([1, 2, 3]))
