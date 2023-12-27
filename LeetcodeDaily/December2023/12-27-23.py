# link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2023-12-27
# difficulty: medium
# date solved: december 27, 2023

class Solution:
    def minCost(self, colors, neededTime):
        minTime = 0
        maxTimeInGroup = 0
        totalGroupTime = 0

        for i in range(len(colors)):
            if i == 0 or colors[i] != colors[i - 1]:
                minTime += totalGroupTime - maxTimeInGroup
                totalGroupTime = 0
                maxTimeInGroup = 0

            totalGroupTime += neededTime[i]
            maxTimeInGroup = max(maxTimeInGroup, neededTime[i])

        minTime += totalGroupTime - maxTimeInGroup

        return minTime



if __name__ == "__main__":
    sol = Solution()
    print(sol.minCost("abaac", [1, 2, 3, 4, 5]))
    print(sol.minCost("abc", [1, 2, 3]))
    print(sol.minCost("aabaa", [1, 2, 3, 4, 1]))
