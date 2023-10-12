# Link: https://leetcode.com/problems/min-stack/
# Difficulty: Easy
# Date solved: Oct 6, 2023
# Solution
# 

class MinStack:

    def __init__(self):
        self.stack = []
        self.minElement = float(inf)
        
    def push(self, val: int) -> None:
        if self.minVal > val:
            self.minVal = val
        self.minList.append(val)

    def pop(self) -> None:
        res = self.minList.pop()
        if len(self.minList) == 0:
            self.minVal = float(inf)
        elif res = self.minVAl:
            self.minVal = min(self.minList)

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minElement
