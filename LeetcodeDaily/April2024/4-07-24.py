# link: https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2024-04-07
# difficulty: medium
# date: april 7, 2024

class Solution:
    def checkValidString(self, s):
        leftMin, leftMax = 0, 0

        for c in s:
            if c == "(":
                leftMin, leftMax = leftMin + 1, leftMax + 1
            elif c == ")":
                leftMin, leftMax = leftMin - 1, leftMax - 1
            else:
                leftMin, leftMax = leftMin - 1, leftMax + 1
            if leftMax < 0:
                return False
            if leftMin < 0:
                leftMin = 0
        return leftMin == 0


if __name__ == "__main__":
    sol = Solution()
    print(sol.checkValidString(s="()"))
    print(sol.checkValidString(s="(*)"))
    print(sol.checkValidString(s="(*))"))
