# Link: https://leetcode.com/problems/balanced-binary-tree/
# Difficulty: Easy
# Date solved: Oct 1, 2023
# Solution
# this is a modifiation on the Max Depth question. It is pretty 
# much the same as max depth but we want to make sure the difference
# between the left and the right dont differ by more than one. 
# if it is, we return -1. We use -1 to signal that it is not balanced
# and we can short cicuit since there is no more reason to check it

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def isBalancedHelper(self, root):
        if root == None:
            return 0
        leftHeight = self.isBalancedHelper(root.left)
        rightHeight = self.isBalancedHelper(root.right)

        if leftHeight == -1 or rightHeight == -1:
            return -1

        if abs(leftHeight - rightHeight) > 1:
            return -1

        return max(leftHeight, rightHeight) + 1

    def isBalanced(self, root):
        return self.isBalancedHelper(root) != -1

