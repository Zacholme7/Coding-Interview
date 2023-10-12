# Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
# Difficulty: Easy
# Date solved: August 30, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root):
        if root == None:
            return 0
        leftHeight = self.maxDepth(root.left) 
        rightHeight = self.maxDepth(root.right)
        return max(leftHeight, rightHeight) + 1
