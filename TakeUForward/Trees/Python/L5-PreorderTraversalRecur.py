# Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
# Difficulty: Easy
# Date solved: August 29, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution: 
    def preorderHelper(self, res, node):
        if node == None:
            return
        res.append(node.val)
        self.preorderHelper(res, node.left)
        self.preorderHelper(res, node.right)
    
    def preorderTraversal(self, root):
        res = []
        if root == None:
            return res
        self.preorderHelper(res, root)
        return res





