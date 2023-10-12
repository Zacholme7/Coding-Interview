# Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
# Difficulty: Easy
# Date solved: August 29, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderHelper(self, res, root):
        if root == None:
            return
        self.postorderHelper(res, root.left)
        self.postorderHelper(res, root.right)
        res.append(root.val)

    def postorderTraversal(self, root):
        res = []
        if root == None:
            return res
        self.postorderHelper(res, root)
        return res