# Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
# Difficulty: Medium
# Date solved: Oct 6, 2023
# Solution
# this is a pretty simple problem. we just want to use a stack
# to evaluate the rpn. If it is not an operator, it is a number and we put it on the
# stack, it is an operator, we pop two numbers off, apply the operation, and then put
# the number back on. The only catch is that you have to reverse the order of the numbers
# for the divison and the subtraction

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = [] 
        for token in tokens:
            if token in ["+", "-", "/", "*"]:
                num1 = stack.pop()
                num2 = stack.pop() 
                if token == "+":
                    stack.append(num1 + num2) 
                elif token == "-":
                    stack.append(num2 - num1) 
                elif token == "/":
                    stack.append(math.trunc(num2 / num1)) 
                else:                      
                    stack.append(num1 * num2)
            else:
                stack.append(int(token))
        return stack.pop()
