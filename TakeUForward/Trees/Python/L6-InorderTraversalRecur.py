# Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
# Difficulty: Easy
# Date solved: August 29, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderHelper(self, res, root):
        if root == None:
            return
        self.inorderHelper(res, root.left)
        res.append(root.val)
        self.inorderHelper(res, root.right)

    def inorderTraversal(self, root):
        res = []
        if root == None:
            return res
        self.inorderHelper(res, root)
        return res
