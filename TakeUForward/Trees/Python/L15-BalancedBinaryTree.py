# Link: https://leetcode.com/problems/balanced-binary-tree/
# Difficulty: Easy
# Date solved: August 30, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalancedHelper(self, node):
        if node == None:
            return 0

        leftHeight = self.isBalancedHelper(node.left)
        rightHeight = self.isBalancedHelper(node.right)

        if leftHeight == -1 or rightHeight == -1:
            return -1
        
        if abs(leftHeight - rightHeight) > 1:
            return -1 

        return max(leftHeight, rightHeight) + 1

    def isBalanced(self, root):
        return self.isBalancedHelper(root) != -1