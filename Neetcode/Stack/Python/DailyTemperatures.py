# Link: https://leetcode.com/problems/daily-temperatures/solutions/1574806/c-easy-standard-sol-intuitive-approach-with-dry-run-stack-appraoch/
# Difficulty: Medium
# Date solved: Oct 17, 2023
# Solution
# this is a little tricky but pretty straightforwards. The trick is to 
# just keep track of the current temperature and its index in a stack
# and when we find a temperatuer that is greater than the top of the stack
# we want to go through all of the values in the stack until we find one that is
# larger or the stack runs out and we want to use the stored indicies to calculate
# the distance between each other and update that spot in the resulting array

class Solution:
    def dailyTemperatures(self, temperatures):
        res = [0] * len(temperatures)
        stack = [] # (temp, idx)
        for idx, temp in enumerate(temperatures):
            while stack and temp > stack[-1][0]:
                stackT, stackIdx = stack.pop()
                res[stackIdx] = (idx - stackIdx)
            stack.append([temp, idx])

        return res

            






