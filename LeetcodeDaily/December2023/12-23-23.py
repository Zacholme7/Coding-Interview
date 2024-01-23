# link: https://leetcode.com/problems/path-crossing/?envType=daily-question&envId=2023-12-23
# difficulty: easy
# date solved: december 23, 2023

class Solution:
    def isPathCrossing(self, path):
        seenPt = set()
        seenPt.add("0,0")
        curX, curY = 0, 0
        for direction in path:
            if direction == "N":
                curY += 1
            elif direction == "E":
                curX += 1
            elif direction == "S":
                curY -= 1
            else:
                curX -= 1

            tmpHash = str(curX) + "," + str(curY)
            if tmpHash in seenPt:
                return True
            seenPt.add(tmpHash)

        return False
