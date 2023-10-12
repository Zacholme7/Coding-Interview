# Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
# Difficulty: Easy
# Date solved: April 27, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root):
        if root == None:
            return []
        res = []
        stack = [root]

        while stack:
            curr = stack.pop()
            res.append(curr.val)

            if curr.right:
                stack.append(curr.right)
            if curr.left:
                stack.append(curr.left)
        return res

