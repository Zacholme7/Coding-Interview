# link: https://leetcode.com/problems/assign-cookies/
# difficulty: easy
# date sovled: january 1, 2024

class Solution:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        childrenPtr, cookiePtr = 0, 0
        numContent = 0
        while childrenPtr < len(g) and cookiePtr < len(s):
            if s[cookiePtr] >= g[childrenPtr]:
                numContent += 1
                childrenPtr += 1
            cookiePtr += 1

        return numContent


if __name__ == "__main__":
    sol = Solution()
    print(sol.findContentChildren([1, 2, 3], [1, 1]))
    print(sol.findContentChildren([1, 2], [1, 2, 3]))


