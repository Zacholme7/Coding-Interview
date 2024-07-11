# link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
# difficulty: medium
# date solved: july 11, 2024

class Solution:
    def reverseParentheses(self, s):
        stack = [""]
        for char in s:
            if char == "(":
                stack.append("(");
            elif char == ")":
                reversed_str = stack.pop()[::-1];
                stack[-1] += reversed_str
            else:
                stack[-1] += char
        return stack[0]





