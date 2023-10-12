# Link: https://leetcode.com/problems/valid-palindrome/
# Difficulty: Easy
# Date solved: Sept 27, 2023
# Solution
# this is a standard two pointer approach. We want to see
# if the sentence is a palindrome meaning that it is spelled the same 
# way forwards and backwards. For this we can have a pointer at the right
# and the left end. While the left is less than thte right, we want to keep checking
# we first check if either the left or the right is not alphanumeric and if that check is false
# then we skip that character because we arent considering non alphanumeric. We can then check if 
# the lowercase version of the left and the right match, if they dont it is not a panlindome, otherwise
# we move the pointers closer to each other

class Solution:
    def isPalindrome(self, s):
        left = 0
        right = len(s) - 1
        while left < right:
            if not s[left].isalnum():
                left += 1
            elif not s[right].isalnum():
                right -= 1
            else:
                if s[left].lower() != s[right].lower():
                    return False
                else:
                    left += 1
                    right -= 1
        return True
