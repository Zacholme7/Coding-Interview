# link: https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26
# difficulty: medium
# date solved: january 26, 2024


class Solution:

    def isOutOfBounds(self, m, n, row, col):
        return row < 0 or row >= m or col < 0 or col >= n

    def findPaths(self, m, n, maxMove, startRow, startColumn):
        mod = 10 ** 9 + 7
        moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        cache = {}

        def helper(movNum, row, col):
            if (movNum, row, col) in cache:
                return cache[(movNum, row, col)]

            if self.isOutOfBounds(m, n, row, col):
                return 1

            if movNum == maxMove:
                return 0

            res = 0
            for dx, dy in moves:
                res += helper(movNum + 1, row + dx, col + dy)
                res %= mod

            cache[(movNum, row, col)] = res
            return res

        return helper(0, startRow, startColumn)


if __name__ == "__main__":
    sol = Solution()
    print(sol.findPaths(2, 2, 2, 0, 0))
    print(sol.findPaths(1, 3, 3, 0, 1))
