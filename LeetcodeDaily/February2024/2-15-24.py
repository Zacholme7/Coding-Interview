# link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
# difficulty: medium
# date solved: february 15, 2024

class Solution:
    def largestPerimeter(self, nums):
        nums.sort()
        res = -1
        total = 0

        for n in nums:
            if total > n:
                res = total + n
            total += n
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.largestPerimeter([5, 5, 5]))
    print(sol.largestPerimeter([1, 12, 1, 2, 5, 50, 3]))
    print(sol.largestPerimeter([5, 5, 50]))
