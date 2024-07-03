# link: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03
# difficulty: medium
# date solved: july 3, 2024

class Solution:
    def minDifference(self, nums):

        # get a sorted list
        nums.sort()

        minDiff = float("Inf")

        for i in range(4):
            startIdx = i
            endIdx = startIdx - 4
            diff = abs(nums[startIdx] - nums[endIdx])
            minDiff = min(minDiff, diff)

        return minDiff

if __name__ == "__main__":
    sol = Solution()
    print(sol.minDifference([1, 5, 0, 10, 14]))
