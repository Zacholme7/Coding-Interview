# link: https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05
# difficulty: easy
# date solved: april 5, 2024
# walkthrough: just a stack based approach, put the characters on the stack and check each time if the letter
# is a pair with the top element, if it is just pop it off since we dont want it

class Solution:
    def makeGood(self, s):
        stack = []
        for char in s:
            if stack and abs(ord(char) - ord(stack[-1])) == 32:
                stack.pop()
            else:
                stack.append(char)
        return "".join(stack)
