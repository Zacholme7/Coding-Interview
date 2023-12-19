# link: https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19
# difficulty: easy
# date solved: december 19, 2023

class Solution:
    def getTotal(self, i, j, grid):
        total = 0
        numCounted = 0
        for dr in range(-1, 2):  # dr is the row offset
            for dc in range(-1, 2):  # dc is the column offset

                r, c = i + dr, j + dc

                if 0 <= r < len(grid) and 0 <= c < len(grid[0]):
                    total += grid[r][c]
                    numCounted += 1
        return total//numCounted

    def imageSmoother(self, img):
        ROWS, COLS = len(img), len(img[0])
        res = [[0] * COLS for _ in range(ROWS)]

        for i in range(ROWS):
            for j in range(COLS):
                total = self.getTotal(i, j, img)
                res[i][j] = total
        return res

                






