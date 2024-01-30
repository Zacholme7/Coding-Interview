# link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30
# difficulty: medium
# date solved: january 30, 2024

import math


class Solution:
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if token in ["+", "-", "*", "/"]:
                num1 = int(stack.pop())
                num2 = int(stack.pop())
                if token == "+":
                    stack.append(num1 + num2)
                elif token == "-":
                    stack.append(num2 - num1)
                elif token == "*":
                    stack.append(num1 * num2)
                elif token == "/":
                    stack.append(math.trunc(num2 / num1))
            else:
                stack.append(token)

        return stack.pop()


if __name__ == "__main__":
    sol = Solution()
    print(sol.evalRPN(["2", "1", "+", "3", "*"]))
    print(sol.evalRPN(["4", "13", "5", "/", "+"]))
    print(sol.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
