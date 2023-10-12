# Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
# Difficulty: Easy
# Date solved: Oct 1, 2023
# Solution
# For this problem we want to invert the binary tree which
# we can do recurively. The base case is when the root is None
# and in that case we can just return None. Our recursive case
# is calling invert on the left and right subtrees and assigning each 
# to the opposite side of the tree. We then need to return the root
# after each call so that it is assigned properly upon return from 
# the recursive call

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root

