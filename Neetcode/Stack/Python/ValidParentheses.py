# Link: https://leetcode.com/problems/valid-parentheses/
# Difficulty: Easy
# Date solved: Sept 26, 2023
# Solution
# this is a stack based question since we want every opening paren
# to have a matching closing one and we want it to be in the reverse
# order that we put them on that stack. We have our stack ds and a 
# dict that will give us easy access to the expected mappings.
# we can loop through and if we see an opening we push it onto 
# the stack. Otherwise it is a closing. We can then check if the 
# paren on the top of the stack is the matching openign to the current
# closing we are on and if it is we remove it from the stack and keep going
# else we return false

class Solution:
    def isValid(self, s: str) -> bool:
        parenMapping = {'{':'}', '[':']', '(':')'}
        stack = []
        for paren in s:
            if paren in parenMapping:
                stack.append(paren)
            else:
                if len(stack) != 0 and parenMapping[stack.pop(-1)] == paren:
                    continue
                else:
                    return False
        return len(stack) == 0


