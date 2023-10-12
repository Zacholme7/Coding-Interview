# Link: https://leetcode.com/problems/diameter-of-binary-tree/
# Difficulty: Easy
# Date solved: August 30, 2023

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterHelper(self, node, maxDia):
        if node == None:
            return 0

        leftHeight = self.diameterHelper(node.left, maxDia)
        rightHeight = self.diameterHelper(node.right, maxDia)

        maxDia = max(maxDia, leftHeight + rightHeight)

        return max(leftHeight, rightHeight) + 1

    def diameterOfBinaryTree(self, root):
        maxDia = 0
        return self.diameterHelper(root, maxDia)
