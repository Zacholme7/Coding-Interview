# Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
# Difficulty: Easy
# Date solved: Oct 1, 2023
# Solution
# this is a standard pattern that follows a lot of tree
# based questions. We want the max height of the binary tree,
# our base case is when we are at the bottom and return zero to start the count
# then we get the left and the right heights and return the max
# of the left or the right plus one to account for the current node

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
